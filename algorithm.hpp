/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:19:36 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/07 18:11:26 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
    /**
     *  @brief Tests a range for element-wise equality.
     *  @param  first1  An input iterator.
     *  @param  last1   An input iterator.
     *  @param  first2  An input iterator.
     *  @return   A boolean true or false.
     *
     *  This compares the elements of two ranges using @c == and returns true or
     *  false depending on whether all of the corresponding elements of the
     *  ranges are equal.
     */
    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        while (first1 != last1)
        {
            // std::cout << *first1 << "&" << *first2 << std::endl;
            if (!(*first1 == *first2))
                return false;
            first1++;
            first2++;
        }
        return true;
    }

    template <class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2,
               BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            first1++;
            first2++;
        }
        return true;
    }

    /**
     *  @brief Performs @b dictionary comparison on 2 ranges.
     *  @param  first1  An input iterator.
     *  @param  last1   An input iterator.
     *  @param  first2  An input iterator.
     *  @param  last2   An input iterator.
     *  @return   A boolean true or false.
     *
     *  Returns true if the sequence of elements defined by the range
     *  [first1,last1) is lexicographically less than the sequence of elements
     *  defined by the range [first2,last2).  Returns false otherwise.
     */
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1 && first2 != last2)
        {
            if (*first1 < *first2)
                return true;
            else if (*first2 < *first1)
                return false;
            first1++;
            first2++;
        }
        return (first2 != last2);
    }

    // Custom one
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2,
                                 Compare comp)
    {
        while (first1 != last1 && first2 != last2)
        {
            if (*first1 < *first2)
                return true;
            else if (comp(first2, *first1))
                return false;
            first1++;
            first2++;
        }
        return (first2 != last2);
    }
} // namespace ft

#endif
