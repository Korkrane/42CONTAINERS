/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:35:39 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/18 23:03:38 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "bidirectional_iterator.hpp"
#include "iterator.hpp"
#include <iostream>

namespace ft
{
    template <typename T>
    class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
        public:
            // typedef T                                                                           value_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type        value_type;
            typedef T                                                                          *pointer;
            typedef T                                                                          &reference;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type   difference_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;

        private:
            pointer _ptr;

        public:
            random_access_iterator()
                : _ptr(ft_nullptr) { } /// default

            virtual ~random_access_iterator() { } // destructor

            pointer base() const
            {
                return _ptr;
            }

            random_access_iterator(const ft::random_access_iterator<T> &other)
                : _ptr(other._ptr) { } // copy

            random_access_iterator &operator=(const ft::random_access_iterator<T> &other)
            {
                if (this != &other)
                    _ptr = other.base();
                return *this;
            } /// assignation

            random_access_iterator(pointer ptr) // new for .begin vector method.
                : _ptr(ptr)
            { }

            random_access_iterator &operator++() // pre
            {
                ++_ptr;
                return *this;
            }

            random_access_iterator operator++(int) // post
            {
                random_access_iterator tmp = *this;
                ++_ptr;
                return tmp;
            }

            random_access_iterator &operator--() // pre
            {
                --_ptr;
                return *this;
            }

            random_access_iterator operator--(int) // post
            {
                random_access_iterator tmp = *this;
                --_ptr;
                return tmp;
            }

            random_access_iterator operator+(difference_type n) const
            {
                return (_ptr + n);
            }

            random_access_iterator operator-(difference_type n) const
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

            operator random_access_iterator<const T>() const // new for const
            {
                return (random_access_iterator<const T>(_ptr));
            }
    };

    template <class T>
    bool operator==(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return (x.base() == y.base());
    }

    // const
    template <typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator==(const ft::random_access_iterator<T_L> x,
               const ft::random_access_iterator<T_R> y)
    {
        return (x.base() == y.base());
    }

    template <class T>
    bool operator!=(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return (x.base() != y.base());
    }

    // const
    template <typename T_L, typename T_R>
    //typename ft::random_access_iterator<T_L>::difference_type
    bool operator!=(const ft::random_access_iterator<T_L> x,
               const ft::random_access_iterator<T_R> y)
    {
        return (x.base() != y.base());
    }

    template <class T>
    bool operator<(const ft::random_access_iterator<T> &x,
                   const ft::random_access_iterator<T> &y)
    {
        return (x.base() < y.base());
    }

    // const
    template <typename T_L, typename T_R>
    //typename ft::random_access_iterator<T_L>::difference_type
    bool operator<(const ft::random_access_iterator<T_L> x,
              const ft::random_access_iterator<T_R> y)
    {
        return (x.base() < y.base());
    }

    template <class T>
    bool operator<=(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return x.base() <= y.base();
    }

    // const
    template <typename T_L, typename T_R>
    //typename ft::random_access_iterator<T_L>::difference_type
    bool operator<=(const ft::random_access_iterator<T_L> x,
               const ft::random_access_iterator<T_R> y)
    {
        return (x.base() <= y.base());
    }

    template <class T>
    bool operator>(const ft::random_access_iterator<T> &x,
                   const ft::random_access_iterator<T> &y)
    {
        return (x.base() > y.base());
    }

    // const
    template <typename T_L,
              typename T_R>
    //typename ft::random_access_iterator<T_L>::difference_type
    bool operator>(const ft::random_access_iterator<T_L> x,
              const ft::random_access_iterator<T_R> y)
    {
        return (x.base() > y.base());
    }

    template <class T>
    bool operator>=(const ft::random_access_iterator<T> &x,
                    const ft::random_access_iterator<T> &y)
    {
        return (x.base() >= y.base());
    }

    // const
    template <typename T_L,
              typename T_R>
    //typename ft::random_access_iterator<T_L>::difference_type
    bool operator>=(const ft::random_access_iterator<T_L> x,
               const ft::random_access_iterator<T_R> y)
    {
        return (x.base() >= y.base());
    }

    template <class T>
    ft::random_access_iterator<T> operator+(
        typename ft::random_access_iterator<T>::difference_type n,
        const ft::random_access_iterator<T>                    &it)
    {
        return it + n;
    }

    template <class T>
    typename ft::random_access_iterator<T>::difference_type operator-(
        const ft::random_access_iterator<T> &x,
        const ft::random_access_iterator<T> &y)
    {
        return x.base() - y.base();
    }

    // const
    /* For iterator - const_iterator */
    template <typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator-(const ft::random_access_iterator<T_L> x,
              const ft::random_access_iterator<T_R> y)
    {
        return (x.base() - y.base());
    }
} // namespace ft

#endif