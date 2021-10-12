/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:35:39 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/12 15:29:21 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCES_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "bidirectional_iterator.hpp"
#include "iterator.hpp"

namespace ft
{
    template <typename T>
    class random_access_iterator : public ft::iterator<ft::random_acces_iterator_tag, T>
    {
        public:
            typedef T value_type;
            typedef T *pointer;
            typedef T &reference;
            typedef typename ft::iteartor<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::iteartor<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;

        public:
            random_acces_iterator()
                : _ptr(nullptr) { } /// default

            virtual ~random_acces_iterator() { } // destructor

            random_acces_iterator(const random_acces_iterator<T> &other)
                : _ptr(other.base()) { } // copy

            random_acces_iterator &operator=(const random_acces_iterator<T> &other)
            {
                if (this != &other)
                    _ptr = other.base();
                return *this;
            } /// assignation

            random_acces_iterator &operator++() // pre
            {
                ++_ptr;
                return *this;
            }
            random_acces_iterator operator++(int) // post
            {
                random_acces_iterator tmp = *this;
                ++_ptr;
                return tmp;
            }
            random_acces_iterator &operator--() // pre
            {
                --_ptr;
                return *this
            }
            random_acces_iterator operator--(int) // post
            {
                random_acces_iterator tmp = *this;
                --_ptr;
                return tmp;
            }

            random_access_iterator operator+(difference_type n)
            {
                return (_ptr + n);
            }

            random_access_iterator operator-(difference_type n)
            {
                return (_ptr - n);
            }

            random_access_iterator &operator+=(difference_type n)
            {
                _ptr += n;
                return (*this);
            }

            random_access_iterator &operator-=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            }
            reference operator[](difference_type n)
            {
                return (*(_ptr + n));
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
    bool operator==(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return x.base() == y.base();
    }

    template <class T>
    bool operator!=(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return x.base() != y.base();
    }

    template <class T>
    bool operator<(const ft::random_access_iterator<T> &x,
                   const ft::random_access_iterator<T> &y)
    {
        return x.base() != y.base();
    }

    template <class T>
    bool operator<=(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return x.base() != y.base();
    }

    template <class T>
    bool operator>(const ft::random_access_iterator<T> &x,
                   const ft::random_access_iterator<T> &y)
    {
        return x.base() != y.base();
    }

    template <class T>
    bool operator>=(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return x.base() != y.base();
    }

    template <class T>
    ft::random_access_iterator<T> operator+(
        typename ft::random_access_iterator<T>::difference_type n,
        const ft::random_access_iterator<T> &it)
    {
        return it + n;
    }

    template <class T>
    typename ft::random_access_iterator<T>::difference_type operator-(
        const ft::random_access_iterator<T> &x,
        const ft::random_access_iterator<T> &y)
    {
        return y.base() - x.base();
    }
} // namespace ft

#endif