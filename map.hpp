/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:45:09 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/13 17:05:45 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>

#ifndef MAP_HPP
#define MAP_HPP

// maps implementation : as BST --> RBTree.

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>>
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const Key, T> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;

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
            allocator_type _alloc;
            Compare _comp;
            _Rb_tree<value_type, Compare> _tree;

        public:
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            // typedef typename iterator;
            // typedef typename const_iterator;
            // typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            // typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;
            // typedef std::size_t size_type;
            // typedef typename ft::iterator_traits<iterator>::diference_type difference_type;

            // commented typedef above are linked to the BST
        public:
            /**
             * @brief Construct a new map object
             *
             * @param comp
             * @param alloc
             */
            explicit map(const key_compare &comp     = key_compare(),
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

            /**
             * @brief Destroy the map object
             *
             */
            ~map() // dtor // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param x
             * @return map&
             */
            map &operator=(const map &x) // assignation operator // NOT FINISHED
                {};

            /// ***iterators***

            /**
             * @brief
             *
             * @return iterator
             */
            iterator begin() // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return const_iterator
             */
            const_iterator begin() const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return iterator
             */
            iterator end() // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return const_iterator
             */
            const_iterator end() const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return reverse_iterator
             */
            reverse_iterator rbegin() // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return const_reverse_iterator
             */
            const_reverse_iterator rbegin() const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return reverse_iterator
             */
            reverse_iterator rend() // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return const_reverse_iterator
             */
            const_reverse_iterator rend() const // NOT FINISHED
                {};

            /// ***capacity***

            /**
             * @brief
             *
             * @return true
             * @return false
             */
            bool empty() const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return size_type
             */
            size_type size() const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return size_type
             */
            size_type max_size() const // NOT FINISHED
                {};

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
                {};

            /**
             * @brief
             *
             * @param position
             * @param val
             * @return iterator
             */
            iterator insert(iterator position, const value_type &val) // with hint insertion // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @tparam InputIterator
             * @param first
             * @param last
             */
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last) // range insertion // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @param position
             */
            void erase(iterator position) // NOT FINISHED
                {};

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
                {};

            /**
             * @brief
             *
             * @param x
             */
            void swap(map &x) // NOT FINISHED
                {};

            /**
             * @brief
             *
             */
            void clear() // NOT FINISHED
                {};

            /// ***observers***

            /**
             * @brief
             *
             * @return key_compare
             */
            key_compare key_comp() const // NOT FINISHED
                {};

            /**
             * @brief
             *
             * @return value_compare
             */
            value_compare value_comp() const // NOT FINISHED
                {};

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
                {};
    };
} // namespace ft

#endif
