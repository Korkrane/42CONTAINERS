/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:47:56 by clorin            #+#    #+#             */
/*   Updated: 2022/04/25 19:47:41 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include "utils/utils.hpp"

#define C_RED "\e[31m"
#define C_BLACK "\e[30m\e[47m"
#define C_RESET "\e[0m"
namespace ft
{
    enum Color
    {
        BLACK,
        RED
    };

    template <class T>
    struct Node
    {
        T data;
        struct Node *parent;
        struct Node *left;
        struct Node *right;
        Color color;

        Node(T data, Node *parent, Node *left, Node *right, Color color) : data(data), parent(parent), left(left), right(right), color(color) {}
    };

    //TODO > > >
    template <class Key, class Value, class KeyOfValue, class Compare = std::less<Key>, class Alloc = std::allocator<Node<Value> > >
    class RBTree
    {
    public:
        typedef Value value_type;
        typedef Key key_type;
        typedef Alloc allocator_type;
        typedef Compare value_compare;
        typedef Node<value_type> node_type;
        typedef Node<value_type> *node_ptr;
        typedef std::size_t size_type;

    private:
        node_ptr _root;
        node_ptr _TNULL;
        value_compare _comp;
        size_type _size;
        allocator_type _alloc;

    public:
        // constructor
        RBTree(const value_compare &comp = value_compare(), const allocator_type alloc = allocator_type()) : _comp(comp), _size(0), _alloc(alloc)
        {
            // construction of leaf _nill (_TNULL)
            _TNULL = _alloc.allocate(1);
            _root = _TNULL;
            _alloc.construct(_TNULL, node_type(value_type(), ft_nullptr_t, ft_nullptr_t, ft_nullptr_t, BLACK));
        }

        virtual ~RBTree()
        {
            clear_recusive(_root);
            _root = _TNULL;
            _alloc.destroy(_TNULL);
            _alloc.deallocate(_TNULL, 1);
        }

        node_ptr getRoot(void) const { return _root; }
        size_type getSize(void) const { return _size; }
        node_ptr getNill(void) const { return _TNULL; }
        size_type max_size(void) const { return _alloc.max_size(); }

        /*              Min and Max
         *   The minimum value of Value is the leftmost node
         *   The maximun value of Value is the right most node */

        node_ptr min(void) const
        {
            return min(_root);
        }

        node_ptr min(node_ptr node) const
        {
            if (node == _TNULL)
                return _root;
            while (node->left != _TNULL)
                node = node->left;
            return node;
        }

        node_ptr max(void) const
        {
            return max(_root);
        }

        node_ptr max(node_ptr node) const
        {
            if (node == _TNULL)
                return _root;
            while (node->right != _TNULL)
                node = node->right;
            return node;
        }

        // insert the key to the tree in its appropriate position
        // and fix the tree
        bool insert(const value_type &data)
        {
            node_ptr new_node;
            new_node = _alloc.allocate(1);
            _alloc.construct(new_node, node_type(data, ft_nullptr_t, _TNULL, _TNULL, RED));
            node_ptr y = ft_nullptr_t;
            node_ptr x = _root;
            while (x != _TNULL)
            {
                y = x;
                /*compare with function compar in KeyOfValue of Data */
                if (_comp(KeyOfValue()(new_node->data), KeyOfValue()(x->data)))
                    x = x->left; // the new_node have to be on left tree
                else if (_comp(KeyOfValue()(x->data), KeyOfValue()(new_node->data)))
                    x = x->right; // the new_code hqve to be right tree
                else
                {
                    // no equal key so delete it
                    _alloc.destroy(new_node);
                    _alloc.deallocate(new_node, 1);
                    return false;
                }
            }
            // y is parent of x is a free place
            new_node->parent = y;
            if (y == ft_nullptr_t)
                _root = new_node; // first Node
            else if (_comp(KeyOfValue()(new_node->data), KeyOfValue()(y->data)))
                y->left = new_node;
            else
                y->right = new_node;
            _size++;
            // if new_node is a root node, color = BLACK & simply return
            if (new_node->parent == ft_nullptr_t)
            {
                new_node->color = BLACK;
                return true;
            }

            // if the grandparent is null, OK return
            if (new_node->parent->parent == ft_nullptr_t)
                return true;
            // if Parent is black nothing to do
            if (new_node->parent->color == BLACK)
                return true;
            // balance of tree
            balance(new_node);
            return true;
        }

        value_type &get_data(node_ptr node = ft_nullptr_t) const
        {
            if (node == ft_nullptr_t)
                node = _root;
            return (node->data);
        }

        int height(node_ptr node = ft_nullptr_t) const
        {
            if (node == ft_nullptr_t)
                node = _root;
            int hl = 0, hr = 0, h = 0;
            if (node == ft_nullptr_t || node == _TNULL)
                h = 0;
            else
            {
                hl = height(node->left);
                hr = height(node->right);

                h = (hl > hr ? hl : hr) + 1;
            }
            return h;
        }

        void print(bool const memory = false) const
        {
            print(memory, _root, "", true);
        }

        bool deleteNode(const key_type &key)
        {
            node_ptr _to_del, _to_control, _tmp;
            Color saved_color;
            bool leaf;

            _to_del = search(key);
            if (_to_del == _TNULL)
                return false; //  not found
            leaf = is_leaf(_to_del);
            saved_color = _to_del->color;
            // if the node to del have only one or no children
            //  juste graft his children (or _nill) to his parent
            if (_to_del->left == _TNULL)
            {
                // Only a right children
                _to_control = _to_del->right;
                graft(_to_del, _to_del->right);
            }
            else if (_to_del->right == _TNULL)
            {
                // only a left children
                _to_control = _to_del->left;
                graft(_to_del, _to_del->left);
            }
            else
            {
                // 2 childrens
                // is replaced by the minimum of it's right branch (successeur)
                _tmp = min(_to_del->right); // search for the minimum in the right child's branch
                saved_color = _tmp->color;
                _to_control = _tmp->right;   // to control right branch
                if (_tmp->parent == _to_del) // the minimum is
                    _to_control->parent = _tmp;
                else
                {
                    graft(_tmp, _tmp->right);
                    _tmp->right = _to_del->right; // the right of tmp is now
                    _tmp->right->parent = _tmp;   // the old right of _to_del
                }
                graft(_to_del, _tmp);
                _tmp->left = _to_del->left; // the left of tmp is now
                _tmp->left->parent = _tmp;  // the old left of _to_del

                _tmp->color = _to_del->color; // the tmp take the color of _to_del
            }
            _alloc.destroy(_to_del); // we now delete the _to_del
            _alloc.deallocate(_to_del, 1);
            _size--;
            if (!leaf && saved_color == BLACK)
                RN_correction(_to_control);
            return true;
        }

        node_ptr search(const key_type &key) const
        {
            return search(_root, key);
        }

        static int max_depth(node_ptr n)
        {
            if (!n)
                return 0;
            return 1 + std::max(max_depth(n->left), max_depth(n->right));
        }

        void swap(RBTree &tree)
        {
            node_ptr tmp_root, tmp_TNULL;
            value_compare tmp_comp;
            size_type tmp_size;
            allocator_type tmp_alloc;

            tmp_root = _root;
            tmp_TNULL = _TNULL;
            tmp_comp = _comp;
            tmp_size = _size;
            tmp_alloc = _alloc;

            this->_root = tree._root;
            this->_TNULL = tree._TNULL;
            this->_comp = tree._comp;
            this->_size = tree._size;
            this->_alloc = tree._alloc;

            tree._root = tmp_root;
            tree._TNULL = tmp_TNULL;
            tree._comp = tmp_comp;
            tree._size = tmp_size;
            tree._alloc = tmp_alloc;
        }

    private:
        node_ptr search(node_ptr node, const key_type &key) const
        {
            if (node == _TNULL)
                return _TNULL;
            if (key == KeyOfValue()(node->data))
                return node;
            if (_comp(key, KeyOfValue()(node->data)))
                return (search(node->left, key));
            else
                return (search(node->right, key));
        }

        void left_rotation(node_ptr x)
        {
            node_ptr y = x->right; // get y (x right child)

            x->right = y->left; // y old left child is now x new right child
            if (y->left != _TNULL)
                y->left->parent = x;
            y->parent = x->parent; // x old parent is now y new parent
            if (x->parent == ft_nullptr_t)
                this->_root = y;
            else if (is_left(x)) // x on left or right ?
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x; // x become y left child
            x->parent = y;
        }

        void right_rotation(node_ptr x)
        {
            node_ptr y = x->left; // y is the left child of x

            x->left = y->right; // y old right child is now x new left child
            if (y->right != _TNULL)
                y->right->parent = x;
            y->parent = x->parent; // x old parent is now y new parent;
            if (x->parent == ft_nullptr_t)
                this->_root = y;
            else if (is_right(x)) // x on left or right ?
                x->parent->right = y;
            else
                x->parent->left = y;
            y->right = x;
            x->parent = y;
        }

        void balance(node_ptr new_node)
        {
            while (new_node->parent->color == RED)
            {
                // parent is RED
                if (new_node == _root)
                    break;
                // check color of uncle
                node_ptr u;
                u = _uncle(new_node);
                if (u->color == RED)
                {
                    // uncle is RED
                    // Grand parent become red, uncle become black, Parent become black
                    new_node->parent->parent->color = RED;
                    u->color = BLACK;
                    new_node->parent->color = BLACK;
                    new_node = new_node->parent->parent; // we check the grand_parent
                }
                else
                {
                    // uncle is BLACK
                    if (is_right(new_node->parent))
                    {
                        // parent is on right of grand-parent
                        if (is_left(new_node))
                        {
                            // newNode is a left child
                            new_node = new_node->parent;
                            right_rotation(new_node);
                        }
                        new_node->parent->color = BLACK;
                        new_node->parent->parent->color = RED;
                        left_rotation(new_node->parent->parent);
                    }
                    else if (is_left(new_node->parent))
                    {
                        // parent is on left side of grand-parent
                        if (is_right(new_node))
                        {
                            // new_node is a right child
                            new_node = new_node->parent;
                            left_rotation(new_node);
                        }
                        new_node->parent->color = BLACK;
                        new_node->parent->parent->color = RED;
                        right_rotation(new_node->parent->parent);
                    }
                }
                if (new_node == _root)
                    break;
            }
            _root->color = BLACK;
        }

        static node_ptr _uncle(node_ptr node)
        {
            node_ptr p = node->parent;
            if (p->parent == ft_nullptr_t) // no grand-parent
                return (ft_nullptr_t);     // no uncle
            return (_brother(p));
        }

        static node_ptr _brother(node_ptr node)
        {
            node_ptr p = node->parent;
            if (p == ft_nullptr_t) // if no parent => no brother
                return ft_nullptr_t;
            if (node == p->left)
                return p->right;
            else
                return p->left;
        }

        static bool is_left(node_ptr node)
        {
            return (node == node->parent->left);
        }
        static bool is_right(node_ptr node)
        {
            return (node == node->parent->right);
        }

        bool is_leaf(node_ptr node) const
        {
            return (node->left == _TNULL && node->right == _TNULL);
        }

        /*clear*/
        void clear_recusive(node_ptr const &node)
        {
            if (node == _TNULL)
                return; // stop of recursive
            clear_recusive(node->left);
            clear_recusive(node->right);

            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            _size--;
        }

        void graft(node_ptr a, node_ptr b) // graft b instead of a
        {
            node_ptr p = a->parent;
            if (p == ft_nullptr_t)
                _root = b;
            else if (is_left(a))
                p->left = b;
            else
                p->right = b;
            b->parent = p;
        }

        void RN_correction(node_ptr node)
        {
            while (node != _root && node->color == BLACK)
            {
                node_ptr brother = _brother(node);
                if (is_left(node))
                {
                    if (brother->color == RED) // CAS 1
                    {
                        brother->color = BLACK;
                        node->parent->color = RED;
                        left_rotation(node->parent);
                        brother = node->parent->right;
                    }

                    if (brother->left->color == BLACK && brother->right->color == BLACK) // the 2 childrens of the brother are BLACK
                    {
                        // CAS 2
                        brother->color = RED; // recoloration but
                        node = node->parent;  // we must control the parent
                    }
                    else // at least one children is RED
                    {
                        if (brother->right->color == BLACK)
                        {
                            // CAS 3
                            brother->left->color = BLACK;
                            node->color = RED;
                            right_rotation(node);
                            brother = node->parent->right;
                        }

                        // CAS 4
                        brother->color = node->parent->color;
                        node->parent->color = BLACK;
                        brother->right->color = BLACK;
                        left_rotation(node->parent);
                        node = _root;
                        break;
                    }
                }
                else // mirror
                {
                    // node is right
                    if (brother->color == RED)
                    {
                        brother->color = BLACK;
                        node->parent->color = RED;
                        right_rotation(node->parent);
                        brother = node->parent->left;
                    }

                    if (brother->left->color == BLACK && brother->right->color == BLACK)
                    {
                        brother->color = RED; // recoloration but
                        node = node->parent;  // we must control parent
                    }
                    else
                    {
                        if (brother->left->color == BLACK)
                        {
                            brother->right->color = BLACK;
                            brother->color = RED;
                            left_rotation(node);
                            brother = node->parent->left;
                        }
                        brother->color = node->parent->color;
                        node->parent->color = BLACK;
                        brother->left->color = BLACK;
                        right_rotation(node->parent);
                        node = _root;
                        break;
                    }
                }
            }
            node->color = BLACK;
        }

        void print(bool memory, node_ptr root, std::string indent = "", bool last = true) const
        {
            if (root != _TNULL)
            {
                std::cout << indent;
                if (last)
                {
                    std::cout << "R----";
                    indent += "     ";
                }
                else
                {
                    std::cout << "L----";
                    indent += "|    ";
                }
                std::string sColor = root->color ? C_RED : C_BLACK;
                std::cout << sColor << KeyOfValue()(root->data) << C_RESET;
                if (memory)
                    std::cout << " " << &root;
                std::cout << std::endl;
                print(memory, root->left, indent, false);
                print(memory, root->right, indent, true);
            }
        }
    };
}

#endif