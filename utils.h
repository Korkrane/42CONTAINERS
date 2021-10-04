/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:17:16 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/04 20:02:44 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

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
			//std::cout << *first1 << "&" << *first2 << std::endl;
			if (!(*first1 == *first2))
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
		return true;
	}

	/**
   *  @brief Struct holding two objects of arbitrary type.
   *
   *  @param T1  Type of first object.
   *  @param T2  Type of second object.
   */
	template <class T1, class T2>
	struct pair
	{
		/// ***Member types***
		typedef T1 first_type;	/// Create an alias "first_type" that refers to T1 type
		typedef T2 second_type; /// Create an alias "seconde type" that refers to T2 type

		/// ***Member objects***
		T1 first; /// T1 could be replaced by first_type
		T2 second;

		/// ***Members functions***
		pair() : first(), second() ///Default ctor
				 {};

		pair(const first_type &a, const second_type &b) : first(a), second(b) /// Initialization ctor
														  {};

		template <class U1, class U2>
		pair(const pair<U1, U2> &p) /// Copy ctor
		{
			first(p.first);
			second(p.second);
		}

		pair &operator=(const pair &p) /// Assignation operator
		{
			first = p.first;
			second = p.second;
			return *this;
		}
	};

	/// ***ft::pair Non members functions overloads***
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
