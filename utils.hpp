/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:45:53 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/18 15:55:13 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static class ft_nullptr_t
{
    public:
        template <class T>
        operator T *() const // convertible to any type of null non-member pointer...
        {
            return 0;
        }

        template <class C, class T>
        operator T C::*() const // or any type of null member pointer...
        {
            return 0;
        }

    private:
        void operator&() const; // Can't take address of nullptr

} ft_nullptr = {};
