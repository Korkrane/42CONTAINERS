/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:45:09 by bahaas            #+#    #+#             */
/*   Updated: 2021/11/02 18:14:59 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>

#ifndef MAP_HPP
#define MAP_HPP

#include "rbtree.hpp"
#include "utility.hpp"
// maps implementation : as BST --> RBTree.

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>>
    class map
    {
        public:
            typedef Key                    key_type;
            typedef T                      mapped_type;
            typedef ft::pair<const Key, T> value_type;
            typedef Compare                key_compare;
            typedef Alloc                  allocator_type;

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                    friend class map<Key, T, Compare, Alloc>;

                protected:
                    Compare comp;

                    value_compare(Compare c)
                        : comp(c) { }

                public:
                    bool operator()(const value_type &x, const value_type &y) const
                    {
                        return comp(x.first, y.first);
                    }
            };

        private:
            typedef RBTree<value_type, value_compare, allocator_type> tree_type;
            tree_type                                                 _tree;
            key_compare                                               _comp;

        public:
            typedef typename tree_type::reference              reference;
            typedef typename tree_type::const_reference        const_reference;
            typedef typename tree_type::pointer                pointer;
            typedef typename tree_type::const_pointer          const_pointer;
            typedef typename tree_type::iterator               iterator;
            typedef typename tree_type::const_iterator         const_iterator;
            typedef typename tree_type::reverse_iterator       reverse_iterator;
            typedef typename tree_type::const_reverse_iterator const_reverse_iterator;
            typedef typename tree_type::difference_type        difference_type;
            typedef typename tree_type::size_type              size_type;

        public:
            /**
             * @brief Construct a new map object
             *
             * @param comp
             * @param alloc
             */
            explicit map(const key_compare    &comp  = key_compare(),
                         const allocator_type &alloc = allocator_type()) // empty ctor // NOT FINISHED
                {};

            /**
             * @brief Construct a new map object
             *
             * @tparam InputIterator
             * @param first
             * @param last
             * @param comp
             * @param alloc
             */
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type()) // range ctor // NOT FINISHED
                {};

            /**
             * @brief Construct a new map object
             *
             * @param x
             */
            map(const map &x) // copy ctor // NOT FINISHED
                {};

            /**:
             * @brief Destroy the map object
             *
             */
            ~map() // dtor // NOT FINISHED
                {};:

            /**
             * @brief
             *
             * @param x
             * @return map&
             */
            map &operator=(const map &x) // assignation operator // NOT FINISHED
            {
                _tree = x._tree;
                return *this;
            };

            /// ***iterators***

            /**
             * @brief
             *
             * @return iterator
             */
            iterator begin() // NOT FINISHED
            {
                return _tree.begin();
            };

            /**
             * @brief
             *
             * @return const_iterator
             */
            const_iterator begin() const // NOT FINISHED
            {
                return _tree.begin();
            };

            /**
             * @brief
             *
             * @return iterator
             */
            iterator end() // NOT FINISHED
            {
                return _tree.end();
            };

            /**
             * @brief
             *
             * @return const_iterator
             */
            const_iterator end() const // NOT FINISHED
            {
                return _tree.end();
            };

            /**
             * @brief
             *
             * @return reverse_iterator
             */
            reverse_iterator rbegin() // NOT FINISHED
            {
                return _tree.rbegin();
            };

            /**
             * @brief
             *
             * @return const_reverse_iterator
             */
            const_reverse_iterator rbegin() const // NOT FINISHED
            {
                return _tree.rbegin();
            };

            /**
             * @brief
             *
             * @return reverse_iterator
             */
            reverse_iterator rend() // NOT FINISHED
            {
                return _tree.rend();
            };

            /**
             * @brief
             *
             * @return const_reverse_iterator
             */
            const_reverse_iterator rend() const // NOT FINISHED
            {
                return _tree.rend();
            };

            /// ***capacity***

            /**
             * @brief
             *
             * @return true
             * @return false
             */
            bool empty() const // NOT FINISHED
            {
                return _tree.empty();
            };

            /**
             * @brief
             *
             * @return size_type
             */
            size_type size() const // NOT FINISHED
            {
                return _tree.size();
            };

            /**
             * @brief
             *
             * @return size_type
             */
            size_type max_size() const // NOT FINISHED
            {
                return _tree.max_size();
            };

            /// ***element access***

            /**
             * @brief
             *
             * @param k
             * @return mapped_type&
             */
            mapped_type &operator[](const key_type &k) // NOT FINISHED
                {};

            /// ***modifiers***

            /**
             * @brief
             *
             * @param val
             * @return ft::pair<iterator, bool>
             */
            ft::pair<iterator, bool> insert(const value_type &val) // single element insertion // NOT FINISHED
            {
                return _tree.insert(val);
            };

            /**
             * @brief
             *
             * @param position
             * @param val
             * @return iterator
             */
            iterator insert(iterator position, const value_type &val) // with hint insertion // NOT FINISHED
            {
                return _tree.insert(position, val);
            };

            /**
             * @brief
             *
             * @tparam InputIterator
             * @param first
             * @param last
             */
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last) // range insertion // NOT FINISHED
            {
                _tree.insert(first, last);
            };

            /**
             * @brief
             *
             * @param position
             */
            void erase(iterator position) // NOT FINISHED
            {
                _tree.erase(position);
            };

            /**
             * @brief
             *
             * @param k
             * @return size_type
             */
            size_type erase(const key_type &k) // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param first
             * @param last
             */
            void erase(iterator first, iterator last) // NOT FINISHED
            {
                _tree.erase(first, last);
            };

            /**
             * @brief
             *
             * @param x
             */
            void swap(map &x) // NOT FINISHED
            {
                _tree.swap(x._tree);
            };

            /**
             * @brief
             *
             */
            void clear() // NOT FINISHED
            {
                _tree.clear();
            };

            /// ***observers***

            /**
             * @brief
             *
             * @return key_compare
             */
            key_compare key_comp() const // NOT FINISHED
            {
                return _comp;
            };

            /**
             * @brief
             *
             * @return value_compare
             */
            value_compare value_comp() const // NOT FINISHED
            {
                return value_compare(_comp);
            };

            /// ***operations***

            /**
             * @brief
             *
             * @param k
             * @return iterator
             */
            iterator find(const key_type &k) // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return const_iterator
             */
            const_iterator find(const key_type &k) const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return size_type
             */
            size_type count(const key_type &k) const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return iterator
             */
            iterator lower_bound(const key_type &k) // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return const_iterator
             */
            const_iterator lower_bound(const key_type &k) const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return iterator
             */
            iterator upper_bound(const key_type &k) // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return const_iterator
             */
            const_iterator upper_bound(const key_type &k) const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return ft::pair<const_iterator, const_iterator>
             */
            ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const // NOT FINSHED
                {};

            /**
             * @brief
             *
             * @param k
             * @return ft::pair<iterator, iterator>
             */
            ft::pair<iterator, iterator> equal_range(const key_type &k) // NOT FINISHED
                {};

            /// ***allocator***

            /**
             * @brief Get the allocator object
             *
             * @return allocator_type
             */
            allocator_type get_allocator() const // NOT FINISHED
            {
                return _tree.get_allocator();
            };
    };
} // namespace ft

#endif
