/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:45:09 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/07 18:16:34 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>

#ifndef MAP_HPP
#define MAP_HPP

namespace ft
{
    //clang-format off
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    //clang-format on
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const Key, T> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;

            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                    friend class map<key_type, mapped_type, key_compare, allocator_type>;

                protected:
                    Compare comp;
                    value_compare(Compare c)
                        : comp(c) { }

                public:
                    bool operator()(const value_type &x, const value_type &y)
                    {
                        return comp(x.first, y.first);
                    }
            };

        private:
        public:
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            // typedef typename ::iterator iterator;
            // typedef typename ::const_iterator const_iterator;
            // typedef typename ::reverse_iterator reverse_iterator;
            // typedef typename ::const_reverse_iterator const_reverse_iterator;
            // typedef typename ::difference_type difference_type;
            // typedef typename ::size_type size_type;

            // maps implementation : as BST --> RBTree. above def are related to my RBTree
    };
} // namespace ft

#endif
