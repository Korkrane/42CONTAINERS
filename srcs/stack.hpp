/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:14:08 by clorin            #+#    #+#             */
/*   Updated: 2022/04/25 18:50:25 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	protected:
		Container c;

	public:
		explicit stack(const container_type &ctnr = container_type()) // ctor
			: c(ctnr)
		{
		}

		virtual ~stack() {} // dtor

		bool empty() const // DONE
		{
			return c.empty();
		}

		size_type size() const // DONE
		{
			return c.size();
		}

		value_type &top() // DONE
		{
			return c.back();
		}

		const value_type &top() const // DONE
		{
			return c.back();
		}

		void push(const value_type &val) // DONE
		{
			c.push_back(val);
		}

		void pop() // DONE
		{
			c.pop_back();
		}

		template <class Tn, class ContainerN>
		friend bool operator==(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

		template <class Tn, class ContainerN>
		friend bool operator!=(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

		template <class Tn, class ContainerN>
		friend bool operator<(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

		template <class Tn, class ContainerN>
		friend bool operator<=(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

		template <class Tn, class ContainerN>
		friend bool operator>(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE

		template <class Tn, class ContainerN>
		friend bool operator>=(const stack<Tn, ContainerN> &x, const stack<Tn, ContainerN> &y); // DONE
	};

	/* *** NON-MEMBER FUNCTION OVERLOADS *** */

	template <class T, class Container>
	bool operator==(const ft::stack<T, Container> &x, const ft::stack<T, Container> &y) // DONE
	{
		return (x.c == y.c);
	};

	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container> &x, const ft::stack<T, Container> &y) // DONE
	{
		return (x.c != y.c);
	};

	template <class T, class Container>
	bool operator<(const ft::stack<T, Container> &x, const ft::stack<T, Container> &y) // DONE
	{
		return (x.c < y.c);
	};

	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container> &x, const ft::stack<T, Container> &y) // DONE
	{
		return (x.c <= y.c);
	};

	template <class T, class Container>
	bool operator>(const ft::stack<T, Container> &x, const ft::stack<T, Container> &y) // DONE
	{
		return (x.c > y.c);
	};

	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &x, const ft::stack<T, Container> &y) // DONE
	{
		return (x.c >= y.c);
	};
} // namespace ft
#endif
