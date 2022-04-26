/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:32:58 by clorin            #+#    #+#             */
/*   Updated: 2021/11/12 11:26:29 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "../iterator.hpp"
# include <sstream>
static	class ft_nullptr_t
	{
		private:
			void operator& () const; //no sens to get adress of nullptr

		public:
			template <class T>
				operator T* () const { return 0;}
			template <class C, class T> 
				operator T C::* () const { return 0;}
	} ft_nullptr_t = {};

namespace ft
{

/*The type T is enabled as member type enable_if::type if Cond is true.
*
*	Otherwise, enable_if::type is not defined.
*/
	template<bool C, class T = void> 
		struct enable_if {};
	template<class T>
		struct enable_if<true, T> 
		{ 
			typedef T type;
		};

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type ret = 0;
		while (first != last)
		{
			first++;
			ret++;
		}
		return ret;
		
	};

	template<class T>
	std::string to_string(T obj)
	{
		std::ostringstream ss;
		ss << obj;
		return (ss.str());
	}

}//ft
#endif
