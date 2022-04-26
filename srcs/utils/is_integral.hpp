/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:35:20 by clorin            #+#    #+#             */
/*   Updated: 2021/11/12 11:26:25 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

/**********************************************************************************
 *				 						IS_INTEGRAL
 * the structure of is_integral for a Type is:
 * 			- type
 * 			- bool
 * 
 * who is stocked in the structure integral_constant for each type.
 * integral_constant is inherits from is_integral_helper to check the differents
 * type.
 * *******************************************************************************/

namespace ft
{
	template <class T,T v>
	struct integral_constant
	{
		static const T		value = v;
		typedef T			value_type;
		typedef integral_constant<T,v> type;
	};

	typedef integral_constant<bool, true> 	true_type;
	typedef integral_constant<bool, false>	false_type;
	// DEFAULT TEMPLATE -> RETURN FALSE
	template <class T>
	struct is_integral: public false_type{};

	// after, all type overloads the structure

	template<>	struct is_integral<bool> : public true_type{};
	template<> 	struct is_integral<char> : public true_type{};
	template<> 	struct is_integral<wchar_t> : public true_type{};
	template<> 	struct is_integral<signed char> : public true_type{};
	template<> 	struct is_integral<short int> : public true_type{};
	template<> 	struct is_integral<int> : public true_type{};
	template<> 	struct is_integral<long int> : public true_type{};
	template<> 	struct is_integral<long long int> : public true_type{};
	template<> 	struct is_integral<unsigned char> : public true_type{};
	template<> 	struct is_integral<unsigned short int> : public true_type{};
	template<> 	struct is_integral<unsigned int> : public true_type{};
	template<> 	struct is_integral<unsigned long int> : public true_type{};
	template<> 	struct is_integral<unsigned long long int> : public true_type{};
	
	template<>	struct is_integral<const bool> : public true_type{};
	template<> 	struct is_integral<const char> : public true_type{};
	template<> 	struct is_integral<const wchar_t> : public true_type{};
	template<> 	struct is_integral<const signed char> : public true_type{};
	template<> 	struct is_integral<const short int> : public true_type{};
	template<> 	struct is_integral<const int> : public true_type{};
	template<> 	struct is_integral<const long int> : public true_type{};
	template<> 	struct is_integral<const long long int> : public true_type{};
	template<> 	struct is_integral<const unsigned char> : public true_type{};
	template<> 	struct is_integral<const unsigned short int> : public true_type{};
	template<> 	struct is_integral<const unsigned int> : public true_type{};
	template<> 	struct is_integral<const unsigned long int> : public true_type{};
	template<> 	struct is_integral<const unsigned long long int> : public true_type{};
} //ft::

#endif
