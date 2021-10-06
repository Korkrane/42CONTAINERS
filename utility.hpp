/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:17:16 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/06 02:01:58 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{

    /**
     *  @brief Struct holding two objects of arbitrary type.
     *
     *  @param T1  Type of first object.
     *  @param T2  Type of second object.
     */
    template <class T1, class T2>
    struct pair {
        /// ***Member types***
        typedef T1 first_type;  /// Create an alias "first_type" that refers to T1 type
        typedef T2 second_type; /// Create an alias "seconde type" that refers to T2 type

        /// ***Member objects***
        T1 first; /// T1 could be replaced by first_type
        T2 second;

        /// ***Members functions***
        pair() :
            first(), second() /// Default ctor
            {};

        pair(const first_type &a, const second_type &b) :
            first(a), second(b) /// Initialization ctor
            {};

        template <class U1, class U2>
        pair(const pair<U1, U2> &p) /// Copy ctor
        {
            first(p.first);
            second(p.second);
        }

        pair &operator=(const pair &p) /// Assignation operator
        {
            first  = p.first;
            second = p.second;
            return *this;
        }
    };

    /// ***ft::pair Non-members functions overloads***
    template <class T1, class T2>
    bool operator==(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
    {
        return (x.first == y.first && x.second == y.second);
    }

    template <class T1, class T2>
    bool operator!=(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
    {
        return !(x == y);
    }

    template <class T1, class T2>
    bool operator<(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
    {
        return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
    }

    template <class T1, class T2>
    bool operator<=(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
    {
        return !(y < x);
    }

    template <class T1, class T2>
    bool operator>(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
    {
        return (y < x);
    }

    template <class T1, class T2>
    bool operator>=(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
    {
        return !(x < y);
    }

    /**
     *  @brief A convenience wrapper for creating a pair from two objects.
     *  @param  x  The first object.
     *  @param  y  The second object.
     *  @return   A newly-constructed pair<> object of the appropriate type.
     */
    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
} // namespace ft

#endif
