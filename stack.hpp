/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:52:43 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/07 18:08:07 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>

namespace ft
{
    //clang-format off
    template <class T, class Container = std::deque<T> >
    //clang-format on
    class stack
    {
        public:
            typedef typename Container::value_type value_type;
            typedef Container container_type;
            typedef typename Container::size_type size_type;

        protected:
            Container c;

        public:
            explicit stack(const container_type &ctnr = container_type())
                : c(ctnr) { }

            bool empty() const
            {
                return c.empty();
            }
            size_type size() const
            {
                return c.size();
            }
            value_type &top()
            {
                return c.back();
            }
            const value_type &ytop()
            {
                return c.back();
            }
            void push(const value_type &val)
            {
                c.push_back(val);
            }
            void pop()
            {
                c.pop_back();
            }
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return x.c == y.c;
    }

    template <class T, class Container>
    bool operator!=(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return !(x == y);
    }

    template <class T, class Container>
    bool operator<(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return x.c < y.c;
    }

    template <class T, class Container>
    bool operator<=(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return !(y < x);
    }

    template <class T, class Container>
    bool operator>(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return y < x;
    }

    template <class T, class Container>
    bool operator>=(const stack<T, Container> &x, const stack<T, Container> &y)
    {
        return !(x < y);
    }
} // namespace ft
