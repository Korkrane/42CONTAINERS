/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:45:25 by clorin            #+#    #+#             */
/*   Updated: 2021/11/22 18:46:21 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

    template <class Input, class Output>
    struct selectFirst : public std::unary_function<Input, Output>
    {
        const Output &operator()(const Input &x) const
        {
            return x.first;
        }
    };

    template <class Input, class Output>
    struct selectKey : public std::unary_function<Input, Output>
    {
        const Output &operator()(const Input &x) const
        {
            return (x);
        }
    };

    template<class T1, class T2>
        struct pair
        {
            typedef T1  first_type;
            typedef T2  second_type;

            //member variables
            first_type      first;
            second_type     second;

            //members functions
            pair(void): first(first_type()), second(second_type()) {};   // default(1)
          template <class U, class V>
            pair(const pair<U,V> &pr):first(pr.first), second(pr.second){};           //copy(2)
            pair(const first_type &a, const second_type &b): first(a), second(b){}; //initialization(3)
            
            pair    &operator=(const pair &pr)
            {
                first   = pr.first;
                second  = pr.second;
                return  *this;
            }

          
        };
        
        template <class T1, class T2>
            ft::pair<T1, T2>    make_pair(T1 x, T2 y)
            {
                return (ft::pair<T1, T2>(x, y));
            }

        //relational operators
        template <class T1, class T2>
            bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { return lhs.first==rhs.first && lhs.second==rhs.second; }

        template <class T1, class T2>
            bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { return !(lhs==rhs); }

        template <class T1, class T2>
            bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

        template <class T1, class T2>
            bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { return !(rhs<lhs); }

        template <class T1, class T2>
            bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { return rhs<lhs; }

        template <class T1, class T2>
            bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { return !(lhs<rhs); }
}   //ft

#endif