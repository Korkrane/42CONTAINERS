/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:43:29 by clorin            #+#    #+#             */
/*   Updated: 2022/04/25 19:24:04 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMES_HPP
#define ALGORITHMES_HPP

/*
 ** LEXICOGRAPHICAL_COMPARE
 ** Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
 ** A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in dictionaries;
 ** It involves comparing sequentially the elements that have the same position in both ranges against each other until one element is not equivalent to the other.
 ** The result of comparing these first non-matching elements is the result of the lexicographical comparison.
 ** If both sequences compare equal until one of them ends, the shorter sequence is lexicographically less than the longer one.
 */

/*
 **  EQUAL
 **  This compares the elements of two ranges using @c == and returns true or
 **  false depending on whether all of the corresponding elements of the
 **  ranges are equal.
 */

namespace ft
{

    // default(1)
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    // custom(2)
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while ((first1 != last1) && (first2 != last2))
        {
            if (comp(*first1, *first2))
                return (true);
            if (comp(*first2, *first1))
                return (false);
            ++first1;
            ++first2;
        }
        return ((first1 == last1) && (first2 != last2));
    }

    // default(1)
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return (false);
            first1++;
            first2++;
        }
        return true;
    }

    // custom(2)
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return (false);
            first1++;
            first2++;
        }
        return true;
    }
}
#endif
