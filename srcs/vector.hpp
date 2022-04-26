/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:22:16 by clorin            #+#    #+#             */
/*   Updated: 2022/04/26 00:57:29 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils/utils.hpp"
# include "utils/algorithmes.hpp"
# include "utils/is_integral.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T														value_type; //data type stored in our vector
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::random_access_iterator<T>					iterator;
			typedef typename ft::random_access_iterator<const T>			const_iterator;
			typedef typename ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename std::size_t									size_type;

		private:
			allocator_type _alloc;
			value_type *_ptr;
			size_type _capacity;
			size_type _size_container; // nb of elem in vector

		public:
			/**
			 * @brief Construct a new vector object (default1)
			 *
			 * @param alloc allocator object
			 */
			explicit vector(const Allocator & alloc = Allocator())
			:_alloc(alloc),
			_ptr(0),
			_capacity(0),
			_size_container(0){};

			/**
			 *  @brief Construct a new vector object (fill2)
			 * 	with n elements. Each element is a copy of val.
			 *
			 * @param n Initial container size
			 * @param val Value to fill the container with. Each element will be initialized to a copy of the value
			 * @param alloc Allocator object
			 * */
			explicit vector(size_t n, const T & val = T(), const Allocator & alloc = Allocator())
			: _alloc(alloc),
			_ptr(0),
			_capacity(n),
			_size_container(n)
			{
				_ptr = _alloc.allocate(n);
				for(size_t i = 0; i < n; i++)
					_alloc.construct(_ptr + i, val);
			};

			/**
			 * @brief Construct a new vector object (range3)
			 * with as many elements as the range [first,last), with each element constructed
			 * from its corresponding element in that range, in the same order.
			 *
			 * @tparam InputIterator
			 * @param first An iterator is the first value in x.
			 * @param last An iterator is the last value in x.
			 * @param alloc allocator object
			 */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator & alloc = Allocator(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr_t) //TODO
			: _alloc(alloc),
			_size_container(0)
			{
				difference_type n = ft::distance(first, last);
				_ptr  = _alloc.allocate(n);
				_capacity = n;
				for(;first != last;first++)
					this->push_back(*first);
			}

			/**
			 * @brief Construct a new vector object (copy4)
			 * with a copy of each of the elements in x, in the same order.
			 *
			 * @param x vector object of the same type
			 */
			vector(vector<T, Allocator> const &x)
			: _alloc(allocator_type()),
			_ptr(0),
			_capacity(0),
			_size_container(0)
			{
				*this = x;
			};

			/**
			 * @brief Assigns new contents to the container,
			 * replacing its current contents, and modifying its size accordingly.
			 *
			 * @param x vector object of the same type
			 * @return *this
			 */
			vector &operator=(vector const & x)
			{
				if (this != &x)
				{
					clear();
					assign(x.begin(), x.end());
				}
				return (*this);
			};

			/**
			 * @brief Destroy the vector object
			 * This destroys all container elements,
			 * and deallocates all the storage capacity allocated by the vector using its allocator.
			 */
			virtual ~vector(void)
			{
				clear();
				if(_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
			};

			// assign (fill)
			void	assign(size_t n, const value_type &val)
			{
				clear();
				if (n == 0)
					return;
				_size_container = 0;
				if (n > _capacity)
				{
					_alloc.deallocate(_ptr, _capacity);
					_ptr = _alloc.allocate(n);
					_capacity = n;
				}
				while(_size_container < n)
				{
					_alloc.construct(_ptr + _size_container, val);
					_size_container++;
				}
			}

			/**
             * @brief Assigns new contents to the vector, replacing its current contents,
             * and modifying its size accordingly. Any elements held in the container before
             * the call are destroyed and replaced by newly constructed elements (no assignments of elements take place).
             * The new contents are elements constructed from each of the elements in the range between first and last, in the same order.
             *
             * @tparam InputIterator
             * @param first the first element in the range.
             * @param last the last element in the range.
             */
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr_t)
			{
				clear();
				if(_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);

				difference_type n = ft::distance(first, last);
                _ptr  = _alloc.allocate(n);
				_capacity = n;
				for(;first != last;first++)
					push_back(*first);
			}

			//modifiers
			void	push_back(const T & val)
			{
				if(_size_container == _capacity)
				{
					empty() ? reserve(1) : reserve(size() * 2);
					//size_t	new_capacity = (_size_container > 0)? _size_container * 2 : 1;
					//this->reserve(new_capacity);
				}
				_alloc.construct(_ptr + _size_container, val);
				_size_container++;
			};

			// remove element

			void pop_back()
			{
				if (_size_container > 0)
				{
					_alloc.destroy(_ptr + (_size_container - 1));
					_size_container--;
				}
			};

			//insert single element(1)
			iterator	insert(iterator position, const value_type &val)
			{
				difference_type index = position - begin();
				insert(position, 1, val);
				return begin() + index;
			}

			//insert fill(2)
			void		insert(iterator position, size_t n, const value_type &val)
			{
				difference_type index = position - begin();
				if(n + _size_container > _capacity)
				{
					// resize
					size_type new_capacity = (_size_container > 0)? (_size_container + n) * 2: n * 2;
					if (new_capacity > max_size()) //TODO what is maxsize
							throw (std::length_error("vector::reserve"));
					else
					{
						value_type	*prev_ptr = _ptr;
						size_type	prev_size = _size_container;
						size_type	prev_capacity = _capacity;
						_ptr = _alloc.allocate(new_capacity);
						_capacity = new_capacity;
						difference_type i = 0;
						for(; i < index; i++)
							_alloc.construct(_ptr + i, *(prev_ptr + i));
						size_type z = i;
						for(size_type j = 0; j < n; j++)
						{
							_alloc.construct(_ptr + i, val);
							i++;
						}
						for(;z < prev_size; z++)
						{
							_alloc.construct(_ptr+i, *(prev_ptr + z));
							i++;
						}
						_alloc.deallocate(prev_ptr, prev_capacity);
						_size_container += n;
					}
				}
				else
				{
					if(position == end())
					{
						for (size_t i = 0; i < n; i++)
							push_back(val);
					}
					else
					{
						difference_type i = index;
						difference_type ending = _size_container - 1;

						while(ending > index)
						{
							_alloc.construct(_ptr + ending + n, *(_ptr + ending));
							ending--;
						}
						_alloc.construct(_ptr + ending + n, *(_ptr + ending));
						i = index;
						for (size_t z = 0; z < n; z++)
						{
							_alloc.construct(_ptr + i, val);
							i++;
						}
						_size_container += n;
					}
				}
			}

			//insert range (3)
			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr_t)
			{
				size_type n = ft::distance(first, last);
				difference_type index = position - begin();
				if(n + _size_container > _capacity)
				{
					// resize
					size_t new_capacity = (_size_container > 0)? (_size_container + n) * 2: n*2;
					if (new_capacity > max_size())
							throw (std::length_error("vector::reserve"));
					else
					{
						value_type	*prev_ptr = _ptr;
						std::size_t	prev_size = _size_container;
						std::size_t	prev_capacity = _capacity;
						_ptr = _alloc.allocate(new_capacity);
						_capacity = new_capacity;
						difference_type i = 0;
						for(; i < index; i++)
							_alloc.construct(_ptr + i, *(prev_ptr + i));
						size_type z = i;
						for(;first != last;first++)
						{
							_alloc.construct(_ptr + (i++),*first);
						}
						for(;z < prev_size; z++)
						{
							_alloc.construct(_ptr+i, *(prev_ptr + z));
							i++;
						}
						_alloc.deallocate(prev_ptr, prev_capacity);
						_size_container += n;
					}
				}
				else
				{
					if(position == end())
					{
						for(;first != last;first++)
							push_back(*first);
					}
					else
					{
						difference_type i = index;
						difference_type ending = _size_container - 1;

						while(ending > index)
						{
							_alloc.construct(_ptr + ending + n, *(_ptr + ending));
							ending--;
						}
						_alloc.construct(_ptr + ending + n, *(_ptr + ending));
						i = index;
						for (;first != last; first++)
						{
							_alloc.construct(_ptr + (i++), *first);
						}
						_size_container += n;
					}
				}

			}

			iterator erase(iterator pos)
			{
				if (empty() || pos == end())
					return end();
				iterator it = begin();
				while (it != pos)
					it++;
				_alloc.destroy(&(*it));
				pointer tmp = &(*(it++));
				pointer ret = tmp;
				while (it != end())
				{
					_alloc.construct(tmp, *it);
					tmp = &(*(it++));
				}
				pop_back(); // destroy the last
				return iterator(ret);
			}

			iterator erase(iterator first, iterator last)
			{
				size_t nb = ft::distance(first, last);
				if (empty())
					return end();
				iterator it = begin();
				while (it != first)
					it++;
				iterator start = it;
				iterator dest = it;
				while (it != last && it != end())
					_alloc.destroy(&(*(it++)));
				while (it != end())
					_alloc.construct(&(*(start++)), *(it++));
				for (size_t i = 0; i < nb; i++)
					pop_back();
				return (dest);
			}

			void		swap(vector &x)
			 {
				pointer			tmp_ptr = _ptr;
				allocator_type	tmp_allocator_type = _alloc;
				size_t			tmp_capacity = _capacity;
				size_t			tmp_size_container = _size_container;

				_alloc = x._alloc;
				_ptr = x._ptr;
				_capacity = x._capacity;
				_size_container = x._size_container;

				x._alloc = tmp_allocator_type;
				x._ptr = tmp_ptr;
				x._capacity = tmp_capacity;
				x._size_container = tmp_size_container;
			 }

			void	clear()
			{
				if(_size_container > 0)
				{
					for(iterator it = this->begin(); it != this->end(); it++)
						_alloc.destroy(&(*it));
					_size_container = 0;
				}
			}

			/* *** CAPACITY FUNCTIONS *** */
			std::size_t		size() const {return(_size_container);};

			std::size_t		capacity() const {return(_capacity);};

			std::size_t		max_size() const {return(Allocator().max_size());};

			bool empty() const { return (size() == 0 ? true : false); };

			void	resize(std::size_t n, T val = T())
			{
				if (n == size())
					return;

				if (n > max_size()) //TODO what is maxsize?
					throw(std::length_error("ft::vector::resize"));
				else if (n < size())
				{
					for(std::size_t i = n; i < _size_container; i++)
						_alloc.destroy(_ptr + i);
					_capacity = n;
				}
				else
				{
					/* If n is greater than the current container size,
					the content is expanded by inserting at the end
					as many elements as needed to reach a size of n.
					If val is specified, the new elements are initialized as
					copies of val, otherwise, they are value-initialized.*/
					reserve(n);
					for(std::size_t i = _size_container; i < n; i++)
						_alloc.construct(_ptr+i, val);
				}
				_size_container = n;
			};

			void	reserve(size_t n)
			{
				if (n > max_size())
					throw (std::length_error("ft::vector::reserve"));
				else if (n > _capacity)
				{
					value_type	*prev_ptr = _ptr;
					std::size_t	prev_size = _size_container;
					std::size_t	prev_capacity = _capacity;
					_ptr = _alloc.allocate(n);
					_capacity = n;
					for(std::size_t i = 0; i < prev_size; i++)
						_alloc.construct(_ptr + i, *(prev_ptr + i));
					_alloc.deallocate(prev_ptr, prev_capacity);
				}
			};

			/* *** ITERATOS *** */
			iterator begin()
			{
				return (iterator(_ptr));
			};

			const_iterator begin() const
			{
				return (const_iterator(_ptr));
			};

			iterator end()
			{
				return (iterator(_ptr + _size_container));
			};

			const_iterator end() const
			{
				return (const_iterator(_ptr + _size_container));
			};

			reverse_iterator rbegin()
			{
				return(reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const
			{
				return(const_reverse_iterator(end()));
			};

			reverse_iterator rend()
			{
				return(reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const
			{
				return(const_reverse_iterator(begin()));
			};

			/* *** ELEMENT ACCESS FUNCTIONS *** */

			reference		front()
			{
				return *begin();
			};

			const_reference front() const
			{
				return *begin();
			};

			reference back()
			{
				return *(end() - 1);
			};

			const_reference	back() const
			{
				return *(end() - 1);
			};

			const_reference at(size_t n) const
			{
				if (n >= size())
					throw(std::out_of_range("ft::vector::at"));
				else
					return (*this)[n];
			};

			reference at(size_t n)
			{
				if (n >= size())
					throw(std::out_of_range("ft::vector::at"));
				else
					return (*this)[n];
			};

			reference		operator[](size_t pos)
			{
				return (_ptr[pos]);
			};

			const_reference	operator[](size_t pos) const
			{
				return (_ptr[pos]);
			};

			/* *** ALLOCATOR GUNCTIONS *** */
			Allocator	get_allocator()const
			{
				return _alloc;
			};
	};

	/* *** NON-MEMBER FUNCTION OVERLOADS *** */

	template <class T, class Allocator>
	bool operator==(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator> &y)
	{
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	};

	template <class T, class Allocator>
	bool operator!=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator> &y)
	{
		return !(x == y);
	};

	template <class T, class Allocator>
	bool operator<(const vector<T, Allocator>& x, const vector<T, Allocator>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	};

	template <class T, class Allocator> // a<=b	->	!(b < a)
	bool operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return (!(y < x));
	};

	template <class T, class Allocator> // a>b	->  b<a
	bool operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return (y < x);
	};

	template <class T, class Allocator> // a>=b	->	!(a<b)
	bool operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return (!(x < y));
	};

	template <class T, class Allocator>
	void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
	{
		x.swap(y);
	};
}
#endif
