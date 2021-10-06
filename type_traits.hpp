/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:48:28 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/06 02:02:00 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{
    /// ENABLE IF
    template <bool, class T = void>
    struct enable_if { };

    template <class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <typename T, T v>
    struct integral_constant {
        static const T                  value = v;
        typedef T                       value_type;
        typedef integral_constant<T, v> type;
                                        operator value_type() const {return value};
    };

    typedef integral_constant<bool, true>  true_type;
    typedef integral_constant<bool, false> false_type;

    /**
     * @brief Check whether T is an integral type.
     * @details Provides the member constant value which is equal to true,
     * if T is the type
     * bool,
     * signed char,
     * unsigned char,
     * wchar_t,
     * char16_t,
     * char32_t,
     * short,
     * int,
     * long,
     * long long,
     * unsigned short,
     * unsigned int,
     * unsigned long,
     * unsigned long long,
     * @param T a type to check.
     */
    template <typename T>
    struct is_integral : public false_type { };

    template <typename T>
    struct is_integral<const T> : public is_integral<T> { };

    template <>
    struct is_integral<bool> : public true_type { };

    template <>
    struct is_integral<signed char> : public true_type { };

    template <>
    struct is_integral<unsigned char> : public true_type { };

    template <>
    struct is_integral<wchar_t> : public true_type { };

    template <>
    struct is_integral<char16_t> : public true_type { };

    template <>
    struct is_integral<char32_t> : public true_type { };

    template <>
    struct is_integral<short> : public true_type { };

    template <>
    struct is_integral<unsigned short> : public true_type { };

    template <>
    struct is_integral<int> : public true_type { };

    template <>
    struct is_integral<unsigned int> : public true_type { };

    template <>
    struct is_integral<long> : public true_type { };

    template <>
    struct is_integral<unsigned long> : public true_type { };

    template <>
    struct is_integral<long long> : public true_type { };

    template <>
    struct is_integral<unsigned long long> : public true_type { };
} // namespace ft

#endif