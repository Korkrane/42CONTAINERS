/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:48:50 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/18 15:51:05 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template <typename T>
    class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
            typedef T                                                                           value_type;
            typedef T                                                                          *pointer;
            typedef T                                                                          &reference;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type   difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;

        protected:
            pointer _ptr;

        public:
            bidirectional_iterator()
                : _ptr(ft_nullptr) { } /// default

            virtual ~bidirectional_iterator() { } // destructor

            bidirectional_iterator(const bidirectional_iterator<T> &other)
                : _ptr(other.base()) { } // copy

            bidirectional_iterator &operator=(const bidirectional_iterator<T> &other)
            {
                if (this != &other)
                    _ptr = other.base();
                return *this;
            } // assignation

            pointer const &base() const
            {
                return _ptr;
            }

            bidirectional_iterator &operator++() // pre
            {
                ++_ptr;
                return *this;
            }
            bidirectional_iterator operator++(int) // post
            {
                bidirectional_iterator tmp = *this;
                ++_ptr;
                return tmp;
            }
            bidirectional_iterator &operator--() // pre
            {
                --_ptr;
                return *this;
            }
            bidirectional_iterator operator--(int) // post
            {
                bidirectional_iterator tmp = *this;
                --_ptr;
                return tmp;
            }
            reference operator*() const
            {
                return *_ptr;
            }
            pointer operator->() const
            {
                // return _ptr;
                return &(operator*());
            }
    };

    template <class T>
    bool operator==(const ft::bidirectional_iterator<T> &x,
                    const ft::bidirectional_iterator<T> &y)
    {
        return x.base() == y.base();
    }

    template <class T>
    bool operator!=(const ft::bidirectional_iterator<T> &x,
                    const ft::bidirectional_iterator<T> &y)
    {
        return x.base() != y.base();
    }
} // namespace ft

#endif // !BIDIRECTIONAL_ITERATOR_HPP