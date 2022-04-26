/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:20:17 by clorin            #+#    #+#             */
/*   Updated: 2022/04/25 21:28:55 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "bidirectional_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "RBTree.hpp"
#include "utils/algorithmes.hpp"
#include <iostream>

namespace ft
{
    // TODO > > >
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class map
    {
    public:
        // types
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef Node<value_type> node_type;
        typedef node_type *node_ptr;
        typedef typename ft::bidirectional_iterator<value_type, node_type> iterator;
        typedef typename ft::bidirectional_iterator<const value_type, const node_type> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename std::size_t size_type;

        typedef ft::RBTree<key_type, value_type, ft::selectFirst<value_type, key_type>, key_compare> tree_type;
        class value_compare;

    private:
        allocator_type _alloc;
        key_compare _comp;
        tree_type _tree;

    public:
        // empty (1)
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree() {}

        // range(2)
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree()
        {
            insert(first, last);
        }

        // copy(3)
        map(const map &cpy)
        {
            insert(cpy.begin(), cpy.end());
        }

        virtual ~map() {} // nothing because except _tree is free with th destructor of RBTree class

        map &operator=(const map &cpy)
        {
            if (this != &cpy)
            {
                clear();
                _alloc = cpy._alloc;
                _comp = cpy._comp;
                this->insert(cpy.begin(), cpy.end());
            }
            return *this;
        }

        /*    ***************************  Iterators  ************************
         *       iterator(_ptr, _root, _nill)
         */

        iterator begin()
        {
            // return first element so the min key value
            return (iterator(_tree.min(), _tree.getRoot(), _tree.getNill()));
        }

        const_iterator begin() const
        {
            return (const_iterator(_tree.min(), _tree.getRoot(), _tree.getNill()));
        }

        iterator end()
        {
            return (iterator(_tree.getNill(), _tree.getRoot(), _tree.getNill()));
        }

        const_iterator end() const
        {
            return (const_iterator(_tree.getNill(), _tree.getRoot(), _tree.getNill()));
        }

        reverse_iterator rbegin() { return (reverse_iterator(end())); }
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }

        reverse_iterator rend() { return (reverse_iterator(begin())); }
        const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }

        /*  ********************** Capacity ***********************/

        bool empty() const { return (_tree.getSize() == 0); }
        size_type size() const { return _tree.getSize(); }
        size_type max_size() const { return _tree.max_size(); }

        /*  ********************* Element Access ******************/

        mapped_type &operator[](const key_type &k)
        {
            node_ptr node = _tree.search(k);
            if (node != _tree.getNill())
                return (node->data.second);
            _tree.insert(value_type(k, mapped_type()));
            node = _tree.search(k);
            return (node->data.second);
        }

        /*  *********************    Modifiers   ***************** */
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            bool succes = _tree.insert(val);
            iterator it = find(val.first);
            return (ft::pair<iterator, bool>(it, succes));
        }
        iterator insert(iterator, const value_type &val)
        {
            return insert(val).first;
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
                _tree.insert(*(first++));
        }

        void erase(iterator position)
        {
            erase((*position).first);
        }

        size_type erase(const key_type &k)
        {
            if (_tree.deleteNode(k))
                return 1;
            else
                return 0;
        }

        void erase(iterator first, iterator last)
        {
            while (first != last)
                erase(first++);
        }

        void clear()
        {
            erase(begin(), end());
        }

        void swap(map &x)
        {
            _tree.swap(x._tree);
        }

        /************************   Observers ***********************/

        key_compare key_comp() const { return _comp; }
        value_compare value_comp() const { return value_compare(_comp); }

        /**************************  operations  ********************/

        iterator find(const key_type &k)
        {
            node_ptr node = _tree.search(k);
            if (node == _tree.getNill())
                return (end());
            return (iterator(node, _tree.getRoot(), _tree.getNill()));
        }

        const_iterator find(const key_type &k) const
        {
            node_ptr node = _tree.search(k);
            if (node == _tree.getNill())
                return (end());
            return (const_iterator(node, _tree.getRoot(), _tree.getNill()));
        }

        size_type count(const key_type &k) const
        {
            node_ptr node = _tree.search(k);
            if (node == _tree.getNill())
                return 0;
            return 1;
        }

        iterator lower_bound(const key_type &k)
        {
            iterator it = begin();
            while (it != end())
            {
                if (_comp((*it).first, k) == false)
                    break;
                it++;
            }
            return (it);
        }

        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator it = begin();
            while (it != end())
            {
                if (_comp((*it).first, k) == false)
                    break;
                it++;
            }
            return (it);
        }

        iterator upper_bound(const key_type &k)
        {
            iterator it = begin();
            while (it != end())
            {
                if (_comp(k, (*it).first) == true)
                    break;
                it++;
            }
            return (it);
        }

        const_iterator upper_bound(const key_type &k) const
        {
            const_iterator it = begin();
            while (it != end())
            {
                if (_comp(k, (*it).first) == true)
                    break;
                it++;
            }
            return (it);
        }

        ft::pair<iterator, iterator> equal_range(const key_type &k)
        {
            return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
        }

        ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
        }

        /*************************** Allocator ***************************/

        allocator_type get_allocator() const { return _alloc; }
    };

    /*      *********** operators relational ***********************/
    // equal
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    // not equal <==> !(==)
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(rhs == lhs));
    }

    // <
    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        // a>b		<==>  b<a
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        // a<=b	->	!(b < a)
        return (!(rhs < lhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        // a>=b	->	!(a<b)
        return (!(lhs < rhs));
    }

    /*      *********** Non-member overload functions ***********/

    template <class Key, class T, class Compare, class Alloc>
    void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    }

    template <class Key, class T, class Compare, class Alloc>
    class map<Key, T, Compare, Alloc>::value_compare
    { // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        // see https://www.cplusplus.com/reference/map/map/value_comp/
        friend class map;

    protected:
        Compare comp;
        value_compare(Compare c) : comp(c) {} // constructed with map's comparison object

    public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator()(const value_type &x, const value_type &y) const
        {
            return comp(x.first, y.first);
        }
    };
} // namespace ft

#endif
