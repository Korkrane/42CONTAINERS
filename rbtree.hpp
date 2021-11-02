/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:24:17 by bahaas            #+#    #+#             */
/*   Updated: 2021/11/02 18:41:41 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <map>
#include <stdio.h>

namespace ft
{
    enum _RB_tree_color
    {
        BLACK,
        RED
    };

    template <typename T>
    class _RB_tree_node
    {
            typedef T                value_type;
            typedef T               &reference;
            typedef T               *pointer;
            typedef const T         &const_reference;
            typedef const T         *const_pointer;
            typedef _RB_tree_node<T> _node;

            _node         *parent;
            _node         *left;
            value_type     data;
            _node         *right;
            _RB_tree_color color;

            RBTreeNode()
                : parent(NULL), left(NULL), data(), right(NULL)
            {
            }

            pointer data_addr()
            {
                return &data;
            }

            const_pointer data_addr() const
            {
                return &data;
            }

            static _node *min(_node *n)
            {
                while (n->left != 0)
                    n = n->left;
                return n;
            }

            static const _node *min(const _node *n)
            {
                while (n->left != 0)
                    n = n->left;
                return n;
            }

            static _node *max(_node *n)
            {
                while (n->right != 0)
                    n = n->right;
                return n;
            }

            static const _node *max(const _node *n)
            {
                while (n->right != 0)
                    n = n->right;
                return n;
            }

            static void left_rotate(_node *x)
            {
                if (!x || !x->right)
                    return;

                _node *y = x->right;

                x->right = y->left;
                if (y->left)
                    y->left->parent = x;

                y->parent = x->parent;
                if (x->parent && x == x->parent->left)
                    x->parent->left = y;
                else if (x->parent && x == x->parent->right)
                    x->parent->right = y;

                y->left   = x;
                x->parent = y;
            }

            static void right_rotate(_node *x)
            {
                if (!x || !x->left)
                    return;

                _node *y = x->left;

                x->left  = y->right;
                if (y->right)
                    y->right->parent = x;

                y->parent = x->parent;
                if (x->parent && x == x->parent->left)
                    x->parent->left = y;
                else if (x->parent && x == x->parent->right)
                    x->parent->right = y;

                y->right  = x;
                x->parent = y;
            }

            static _node *successor(_node *n, _node *start)
            {
                if (n->right)
                    return min(n->right, start);

                _node *parent = n->parent;
                while (parent != NULL && n == parent->right)
                {
                    n      = parent;
                    parent = n->parent;
                }
                return parent;
            }

            static _node *predecessor(_node *n, _node *end)
            {
                if (n->left)
                    return max(n->left, end);

                _node *parent = n->parent;
                while (parent != NULL && n == parent->left)
                {
                    n      = parent;
                    parent = n->parent;
                }
                return parent;
            }
    };

    template <typename T>
    class RB_tree_iterator
    {
        public:
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef T                               value_type;
            typedef T                              &reference;
            typedef T                              *pointer;
            typedef std::ptrdiff_t                  difference_type;
            typedef RBTreeNode<T>                   Node;

        private:
            Node *current;
            Node *start;
            Node *end;

        public:
            RB_tree_iterator(Node *n = NULL, Node *sstart = NULL, Node *send = NULL)
                : current(n), start(sstart), end(send)
            {
            }

            RB_tree_iterator(const RB_tree_iterator &other)
            {
                *this = other;
            }

            RB_tree_iterator &operator=(const RB_tree_iterator &other)
            {
                current = other.current;
                start   = other.start;
                end     = other.end;

                return *this;
            }

            ~RB_tree_iterator()
            {
            }

            bool operator==(const RB_tree_iterator &b) const
            {
                return current == b.current;
            }

            bool operator!=(const RB_tree_iterator &b) const
            {
                return !(*this == b);
            }

            reference operator*() const
            {
                return current->data;
            }

            pointer operator->() const
            {
                return current->data_addr();
            }

            RB_tree_iterator &operator++() // ++it
            {
                current = Node::successor(current, start);
                return *this;
            }

            RB_tree_iterator operator++(int) // it++
            {
                RB_tree_iterator it(*this);
                current = Node::successor(current, start);
                return it;
            }

            RB_tree_iterator &operator--() // --it
            {
                current = Node::predecessor(current, end);
                return *this;
            }

            RB_tree_iterator operator--(int) // it--
            {
                RB_tree_iterator it(*this);
                current = Node::predecessor(current, end);
                return it;
            }

            Node *ptr() const
            {
                return current;
            }

            Node *start_ptr() const
            {
                return start;
            }

            Node *end_ptr() const
            {
                return end;
            }
    };

    template <typename T>
    class RB_tree_const_iterator
    {
        public:
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef T                               value_type;
            typedef const T                        &reference;
            typedef const T                        *pointer;
            typedef std::ptrdiff_t                  difference_type;
            typedef RBTreeNode<T>                   Node;

        private:
            Node *current;
            Node *start;
            Node *end;

        public:
            RB_tree_const_iterator(Node *n = NULL, Node *sstart = NULL, Node *send = NULL)
                : current(n), start(sstart), end(send)
            {
            }

            RB_tree_const_iterator(const RB_tree_const_iterator &other)
            {
                *this = other;
            }

            RB_tree_const_iterator(const RBTreeIterator<value_type> &other)
            {
                *this = other;
            }

            RB_tree_const_iterator &operator=(const RB_tree_const_iterator &other)
            {
                current = other.current;
                start   = other.start;
                end     = other.end;

                return *this;
            }

            RB_tree_const_iterator &operator=(const RBTreeIterator<value_type> &other)
            {
                current = other.ptr();
                start   = other.start_ptr();
                end     = other.end_ptr();

                return *this;
            }

            operator RBTreeIterator<value_type>() const
            {
                return RBTreeIterator<value_type>(current, start, end);
            }

            ~RB_tree_const_iterator()
            {
            }

            bool operator==(const RB_tree_const_iterator &b) const
            {
                return current == b.current;
            }

            bool operator!=(const RB_tree_const_iterator &b) const
            {
                return !(*this == b);
            }

            reference operator*() const
            {
                return current->data;
            }

            pointer operator->() const
            {
                return current->data_addr();
            }

            RB_tree_const_iterator &operator++() // ++it
            {
                current = Node::successor(current, start);
                return *this;
            }

            RB_tree_const_iterator operator++(int) // it++
            {
                RB_tree_const_iterator it(*this);
                current = Node::successor(current, start);
                return it;
            }

            RB_tree_const_iterator &operator--() // --it
            {
                current = Node::predecessor(current, end);
                return *this;
            }

            RB_tree_const_iterator operator--(int) // it--
            {
                RB_tree_const_iterator it(*this);
                current = Node::predecessor(current, end);
                return it;
            }
    };

    template <typename T, typename Compare, typename Alloc>
    class RBTree
    {
        public:
            typedef T       value_type;
            typedef Compare compare_type;
            typedef Alloc   allocator_type;

            typedef value_type       &reference;
            typedef const value_type &const_reference;
            typedef value_type       *pointer;
            typedef const value_type *const_pointer;

            typedef std::ptrdiff_t difference_type;
            typedef std::size_t    size_type;

        private:
            typedef RBTreeNode<value_type> Node;

        public:
            typedef RBTreeIterator<value_type>          iterator;
            typedef RBTreeConstIterator<value_type>     const_iterator;
            typedef ft::ReverseIterator<iterator>       reverse_iterator;
            typedef ft::ReverseIterator<const_iterator> const_reverse_iterator;

            RBTree(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type())
                : root(NULL), _size(0), sentinelStart(NULL), sentinelEnd(NULL), _comp(comp), _alloc(alloc), _clear(true)
            {
                __init_tree();
            }

            template <class InputIterator>
            RBTree(InputIterator first, InputIterator last, const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type())
                : root(NULL), _size(0), sentinelStart(NULL), sentinelEnd(NULL), _comp(comp), _alloc(alloc), _clear(true)
            {
                __init_tree();
                insert(first, last);
            }

            RBTree(const RBTree &other)
                : root(NULL), _size(0), sentinelStart(NULL), sentinelEnd(NULL), _comp(other._comp), _alloc(other._alloc), _clear(true)
            {
                *this = other;
            }

            ~RBTree()
            {
                if (_clear)
                {
                    __clear();
                    destroy_node(sentinelEnd);
                    destroy_node(sentinelStart);
                }
            }

            RBTree &operator=(const RBTree &other)
            {
                // Reset tree before any assignation (no reset of _alloc and _comp)
                __clear();
                if (sentinelStart)
                    destroy_node(sentinelStart);
                if (sentinelEnd)
                    destroy_node(sentinelEnd);
                root = sentinelStart = sentinelEnd = NULL;

                if (!other.empty())
                {
                    root    = __copy_tree(other.root, NULL);
                    _size   = other._size;

                    Node *n = root;
                    while (n && n->left)
                        n = n->left;
                    sentinelStart = n;

                    n             = root;
                    while (n && n->right)
                        n = n->right;
                    sentinelEnd = n;
                }
                else
                {
                    root = sentinelEnd = create_node();
                    sentinelStart      = create_node();
                    root->color = sentinelStart->color = BLACK;
                }

                return *this;
            }

            iterator begin()
            {
                if (empty())
                    return end();
                return iterator(sentinelStart->parent, sentinelStart, sentinelEnd);
            }

            iterator end()
            {
                return iterator(sentinelEnd, sentinelStart, sentinelEnd);
            }

            const_iterator begin() const
            {
                if (empty())
                    return end();
                return const_iterator(sentinelStart->parent, sentinelStart, sentinelEnd);
            }

            const_iterator end() const
            {
                return const_iterator(sentinelEnd, sentinelStart, sentinelEnd);
            }

            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }

            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }

            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            }

            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(begin());
            }

            bool empty() const
            {
                return _size == 0;
            }

            size_type size() const
            {
                return _size;
            }

            size_type max_size() const
            {
                return allocator_node.max_size();
            }

            pair<iterator, bool> insert(const_reference val)
            {
                Node *node = create_node(val);

                if (empty())
                {
                    __insert_empty(node);
                    return ft::make_pair(iterator(root, sentinelStart, sentinelEnd), true);
                }

                iterator it;
                if ((it = __insert_bst(node)) != end())
                {
                    destroy_node(node);
                    return ft::make_pair(it, false);
                }

                if (node->parent && node->parent->parent)
                    __insert_rebalance_tree(node);
                return ft::make_pair(iterator(node, sentinelStart, sentinelEnd), true);
            }

            iterator insert(iterator position, const_reference val)
            {
                (void)position;
                return insert(val).first;
            }

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                for (; first != last; first++)
                    insert(*first);
            }

            size_type erase(const_reference val)
            {
                Node *node = __find(val);

                if (!node)
                    return (0);

                __bst_delete_node(node);

                return (1);
            }

            void erase(iterator position)
            {
                iterator last = position;
                last++;
                erase(position, last);
            }

            void erase(iterator first, iterator last)
            {
                if (first == end())
                    return;

                if (first == begin() && last == end())
                {
                    clear();
                    return;
                }

                size_type n = 0;
                iterator  f = first;
                for (; f != last; f++) // Complexity n (insignificant in front of nlog(n))
                    n++;

                if (n < _size / 2)
                {
                    Node      *nf = first.ptr();
                    value_type l  = *last; // using l is possible thanks to the uniqueness of the values in the tree

                    while (nf->data != l)
                        nf = __bst_delete_node(nf);
                }
                else // Will regenerate tree only if more than the half of it must be erased...
                    __regenerate_tree(first, last);
            }

            void swap(RBTree &x)
            {
                ft::__swap(root, x.root);
                ft::__swap(sentinelStart, x.sentinelStart);
                ft::__swap(sentinelEnd, x.sentinelEnd);
                ft::__swap(_size, x._size);
                ft::__swap(_clear, x._clear);
            }

            void clear()
            {
                __clear();
            }

            iterator find(const_reference val)
            {
                Node *f = __find(val);

                if (!f)
                    return end();
                return iterator(f, sentinelStart, sentinelEnd);
            }

            const_iterator find(const_reference val) const
            {
                Node *f = __find(val);

                if (!f)
                    return end();
                return const_iterator(f, sentinelStart, sentinelEnd);
            }

            size_type count(const_reference val) const
            {
                return __find(val) ? 1 : 0;
            }

            iterator lower_bound(const_reference val)
            {
                iterator it;
                for (it = begin(); it != end() && _comp(*it, val); it++)
                    ;
                return it;
            }

            const_iterator lower_bound(const_reference val) const
            {
                const_iterator it;
                for (it = begin(); it != end() && _comp(*it, val); it++)
                    ;
                return it;
            }

            iterator upper_bound(const_reference val)
            {
                iterator it;
                for (it = begin(); it != end() && !_comp(val, *it); it++)
                    ;
                return it;
            }

            const_iterator upper_bound(const_reference val) const
            {
                const_iterator it;
                for (it = begin(); it != end() && !_comp(val, *it); it++)
                    ;
                return it;
            }

            pair<iterator, iterator> equal_range(const_reference val)
            {
                return ft::make_pair(lower_bound(val), upper_bound(val));
            }

            pair<const_iterator, const_iterator> equal_range(const_reference val) const
            {
                return ft::make_pair(lower_bound(val), upper_bound(val));
            }

            allocator_type get_allocator() const
            {
                return _alloc;
            }

        private:
            Node          *root;
            size_type      _size;
            Node          *sentinelStart;
            Node          *sentinelEnd;
            compare_type   _comp;
            allocator_type _alloc;
            bool           _clear;

            typename allocator_type::template rebind<Node>::other allocator_node;

            void __init_tree()
            {
                sentinelEnd        = create_node();
                sentinelStart      = create_node();
                sentinelEnd->color = sentinelStart->color = BLACK;
                root                                      = sentinelEnd;

                _clear                                    = true;
            }

            Node *create_node(const_reference val = value_type())
            {
                Node *node = allocator_node.allocate(1);
                allocator_node.construct(node, Node());

                _alloc.construct(node->data_addr(), val);

                node->color = RED;
                return node;
            }

            void destroy_node(Node *node)
            {
                _alloc.destroy(node->data_addr());
                allocator_node.destroy(node);
                allocator_node.deallocate(node, 1);
            }

            Node *__find(const_reference val, Node **leaf = NULL)
            {
                Node *node = root;

                while (node && node != sentinelEnd && node != sentinelStart)
                {
                    if (leaf)
                        *leaf = node;
                    if (_comp(val, node->data))
                        node = node->left;
                    else if (_comp(node->data, val))
                        node = node->right;
                    else
                        return node;
                }
                return NULL;
            }

            Node *__find(const_reference val, Node **leaf = NULL) const
            {
                Node *node = root;

                while (node && node != sentinelEnd && node != sentinelStart)
                {
                    if (leaf)
                        *leaf = node;
                    if (_comp(val, node->data))
                        node = node->left;
                    else if (_comp(node->data, val))
                        node = node->right;
                    else
                        return node;
                }
                return NULL;
            }

            void __clear()
            {
                __clear_helper(root);
                _size = 0;
                root  = sentinelEnd;
            }

            void __clear_helper(Node *node)
            {
                if (!node || node == sentinelStart || node == sentinelEnd)
                    return;
                __clear_helper(node->left);
                __clear_helper(node->right);
                destroy_node(node);
            }

            void __left_rotate(Node *x)
            {
                Node::left_rotate(x);

                if (!x->parent->parent)
                    root = x->parent;
            }

            void __right_rotate(Node *x)
            {
                Node::right_rotate(x);

                if (!x->parent->parent)
                    root = x->parent;
            }

            void __insert_empty(Node *node)
            {
                root                  = node;
                root->left            = sentinelStart;
                root->right           = sentinelEnd;
                sentinelStart->parent = sentinelEnd->parent = root;
                _size++;

                root->color = BLACK;
            }

            iterator __insert_bst(Node *node)
            {
                Node *target;
                Node *n;

                if ((n = __find(node->data, &target)))
                    return iterator(n, sentinelStart, sentinelEnd);

                node->parent = target;
                if (_comp(node->data, target->data))
                {
                    if (target->left)
                        target->left->parent = node;
                    node->left   = target->left; // target->left can either be NULL or sentinelStart
                    target->left = node;
                }
                else
                {
                    if (target->right)
                        target->right->parent = node;
                    node->right   = target->right; // same as the left case, but with sentinelEnd...
                    target->right = node;
                }
                _size++;
                return end(); // If it is not a duplicate, insertion will go well
            }

            void __insert_rebalance_tree(Node *node)
            {
                while (node != root && node->parent->color == RED)
                {
                    Node *parent       = node->parent;
                    Node *grand_parent = node->parent->parent;
                    Node *uncle;

                    if (parent == grand_parent->left) // Parent is left child
                    {
                        uncle = grand_parent->right;
                        if (uncle && uncle->color == RED)
                        {
                            uncle->color = parent->color = BLACK;
                            grand_parent->color          = RED;
                            node                         = grand_parent;
                        }
                        else
                        {
                            if (node == parent->right) // Current node is right child
                            {
                                node = parent;
                                __left_rotate(node);
                            }
                            node->parent->color         = BLACK;
                            node->parent->parent->color = RED;
                            __right_rotate(node->parent->parent);
                        }
                    }
                    else // parent is right child
                    {
                        uncle = grand_parent->left;
                        if (uncle && uncle->color == RED)
                        {
                            uncle->color = parent->color = BLACK;
                            grand_parent->color          = RED;
                            node                         = grand_parent;
                        }
                        else
                        {
                            if (node == parent->left) // Current node is left child
                            {
                                node = parent;
                                __right_rotate(node);
                            }
                            node->parent->color         = BLACK;
                            node->parent->parent->color = RED;
                            __left_rotate(node->parent->parent);
                        }
                    }
                }

                root->color = BLACK;
            }

            bool __is_null(Node *n)
            {
                return n == NULL || n == sentinelStart || n == sentinelEnd;
            }

            bool __is_black(Node *n)
            {
                return n == NULL || n->color == BLACK;
            }

            Node *__node_sibling(Node *n)
            {
                if (!n->parent)
                    return NULL;
                else if (n == n->parent->left)
                    return n->parent->right;
                else
                    return n->parent->left;
            }

            Node *__get_bst_replacement(Node *n)
            {
                if (!__is_null(n->left) && !__is_null(n->right))
                    return Node::successor(n, sentinelStart);
                else if (__is_null(n->left) && __is_null(n->right))
                    return NULL;
                else if (!__is_null(n->left))
                    return n->left;
                else
                    return n->right;
            }

            void __bst_delete_leaf(Node *v, bool uvBlack)
            {
                Node *parent = v->parent;

                if (v == root)
                {
                    root                = sentinelEnd;
                    sentinelEnd->parent = sentinelStart->parent = NULL; // Tree is empty
                    _size                                       = 0;
                }
                else
                {
                    if (uvBlack)
                        __delete_rebalance_tree(v);
                    else if (v == parent->left && parent->right) // check color of sibling
                        parent->right->color = RED;
                    else if (parent->left) // v is on right...
                        parent->left->color = RED;

                    if (v == parent->left)
                    {
                        parent->left = v->left;
                        if (v->left)
                            v->left->parent = parent;
                    }
                    else
                    {
                        parent->right = v->right;
                        if (v->right)
                            v->right->parent = parent;
                    }
                }
                destroy_node(v);
            }

            void __bst_delete_one_child(Node *u, Node *v, bool uvBlack)
            {
                Node *parent = v->parent;

                if (v == root) // In this case, there is exactly 2 nodes in the tree...
                {
                    ft::__swap(u->data, v->data);
                    v->left  = sentinelStart;
                    v->right = sentinelEnd;
                    destroy_node(u); // Data swapped with v, to erase all at once...
                }
                else
                {
                    if (v == parent->left) // Disconnect v from tree, and replace it with u
                        parent->left = u;
                    else
                        parent->right = u;
                    destroy_node(v);
                    u->parent = parent;

                    if (uvBlack)
                        __delete_rebalance_tree(u);
                    else
                        u->color = BLACK;
                }
            }

            Node *__bst_delete_node(Node *v)
            {
                Node *u      = __get_bst_replacement(v);
                Node *succ   = Node::successor(v, sentinelStart);

                bool uvBlack = __is_black(u) && __is_black(v);

                if (!u)
                {
                    _size--;
                    __bst_delete_leaf(v, uvBlack);
                    return succ;
                }
                else if (__is_null(v->left) || __is_null(v->right))
                {
                    _size--;
                    __bst_delete_one_child(u, v, uvBlack);
                    return succ;
                }

                ft::__swap(u->data, v->data);
                __bst_delete_node(u);
                return v; // We want the position of the successor (which is v, because of the swap)
            }

            void __delete_rebalance_tree(Node *x)
            {
                if (x == root)
                    return;

                Node *sibling = __node_sibling(x), *parent = x->parent;
                if (!sibling) // No sibling -> push black-black to parent
                {
                    __delete_rebalance_tree(parent);
                    return;
                }
                if (sibling->color == RED) // sibling is red -> parent red + sibling black + rotate
                {
                    parent->color  = RED;
                    sibling->color = BLACK;
                    if (sibling == parent->left)
                        __right_rotate(parent);
                    else
                        __left_rotate(parent);
                    __delete_rebalance_tree(x);
                }
                else // Sibling is black...
                {
                    if (!__is_black(sibling->left) || !__is_black(sibling->right)) // At least one red child
                    {
                        if (!__is_black(sibling->left)) // left child of sibling is red
                        {
                            if (sibling == parent->left)
                            { // Left left
                                sibling->left->color = sibling->color;
                                sibling->color       = parent->color; // pushing down color par -> sib -> child
                                __right_rotate(parent);
                            }
                            else
                            { // left right
                                sibling->left->color = parent->color;
                                __right_rotate(sibling);
                                __left_rotate(parent);
                            }
                        }
                        else // right child of sibling is red...
                        {
                            if (sibling == parent->right) // Mirror cases...
                            {                             // Right right
                                sibling->right->color = sibling->color;
                                sibling->color        = parent->color; // pushing down color par -> sib -> child
                                __left_rotate(parent);
                            }
                            else
                            { // Right left
                                sibling->right->color = parent->color;
                                __left_rotate(sibling);
                                __right_rotate(parent);
                            }
                        }
                        parent->color = BLACK;
                    }
                    else
                    {
                        sibling->color = RED;
                        if (parent->color == BLACK)
                            __delete_rebalance_tree(parent);
                        else
                            parent->color = BLACK;
                    }
                }
            }

            void __regenerate_tree(iterator first, iterator last) // Regenerates tree without unwanted elements
            {
                RBTree rbt(_comp, _alloc);

                for (iterator it = begin(); it != end(); it++)
                {
                    if (first == last || _comp(*it, *first) || _comp(*first, *it))
                        rbt.insert(*it);
                    else
                        first++;
                }
                rbt._clear = false; // Mandatory to block double free (rbt's destructor will not free anything)

                __clear();
                destroy_node(sentinelEnd);
                destroy_node(sentinelStart);
                root          = rbt.root;
                sentinelStart = rbt.sentinelStart;
                sentinelEnd   = rbt.sentinelEnd;
                _size         = rbt._size;
            }

            Node *__copy_tree(Node *n, Node *parent = NULL) // Copies tree starting from n
            {
                if (!n) // Hard copy of every node in the tree (including sentinels)
                    return NULL;

                Node *node   = create_node(n->data);
                node->parent = parent;
                node->color  = n->color;
                node->left   = __copy_tree(n->left, node);
                node->right  = __copy_tree(n->right, node);

                return node;
            }
    };
} // namespace ft

#endif // !RBTREE_HPP