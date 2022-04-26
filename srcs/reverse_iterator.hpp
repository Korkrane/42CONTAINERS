/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:00:31 by clorin            #+#    #+#             */
/*   Updated: 2022/04/25 18:47:21 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {

    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;

    protected:
        Iterator _ptr;

    public:
        reverse_iterator() : _ptr() {}
        explicit reverse_iterator(Iterator it) : _ptr(it) {}

        template <class U>
        reverse_iterator(reverse_iterator<U> const &rev_it)
            : _ptr(rev_it.base()){};

        virtual ~reverse_iterator(){};

        template <class U>
        reverse_iterator &operator=(reverse_iterator<U> const &rev_it)
        {
            _ptr = rev_it.base();
            return *this;
        }

        iterator_type base() const
        {
            return _ptr;
        }

        reference operator*() const
        {
            Iterator tmp = _ptr;
            return (*--tmp);
        }

        pointer operator->() const
        {
            return &(this->operator*());
        }

        reference operator[](difference_type n) const
        {
            return base()[-n - 1];
        }

        reverse_iterator &operator++() // pre-increment
        {
            _ptr--;
            return *this;
        }

        reverse_iterator operator++(int) // post-increment
        {
            reverse_iterator tmp = *this;
            _ptr--;
            return tmp;
        }

        reverse_iterator &operator--() // pre-decrement
        {
            _ptr++;
            return *this;
        }

        reverse_iterator operator--(int) // post-decrement
        {
            reverse_iterator tmp = *this;
            _ptr++;
            return tmp;
        }

        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator<iterator_type>(_ptr - n);
        }

        reverse_iterator operator-(difference_type n) const
        {
            return reverse_iterator<iterator_type>(_ptr + n);
        }

        /*
        difference_type operator+(const Iterator &src) const
        {
            return (_ptr - src._ptr);
        }
        difference_type operator-(const Iterator &src) const
        {
            return (_ptr + src._ptr);
        }
        */

        reverse_iterator &operator+=(difference_type n)
        {
            _ptr -= n;
            return *this;
        }

        reverse_iterator &operator-=(difference_type n)
        {
            _ptr += n;
            return *this;
        }

        /*
                template <class Iterator1>
                friend difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator1> &rhs);
                template <class Iterator1, class Iterator2>
                friend typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs);
                */
    };

    /* *** NON-MEMBER FUNCTION OVERLOADS *** */

    // comparison
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    };

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    };

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    };

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    };

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    };

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    };

    template <class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    };

    template <class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() != rhs.base());
    };

    template <class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() > rhs.base());
    };

    template <class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    };

    template <class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() < rhs.base());
    };

    template <class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    };

    // operator +
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return (rev_it + n);
    };

    template <class Iter1, class Iter2>
    reverse_iterator<Iter1> operator+(typename reverse_iterator<Iter1>::difference_type n, const reverse_iterator<Iter2> &rev_it)
    {
        return (rev_it + n);
    };

    // operator -
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return ((rhs._ptr - lhs._ptr));
    };

    template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return ((rhs._ptr - lhs._ptr));
    };
}
#endif
