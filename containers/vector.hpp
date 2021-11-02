/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:34:39 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/26 14:20:08 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "algorithm.hpp" //lexico_compar
#include "iterator.hpp"  //reverse_it //distance
#include "random_access_iterator.hpp"
#include "type_traits.hpp" //enable_if
#include <iostream>        //std::allocator

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                                       value_type;     // represents the data type stored
            typedef Alloc                                                   allocator_type; // represents the allocator class used
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename ft::random_access_iterator<value_type>         iterator;
            typedef typename ft::random_access_iterator<const value_type>   const_iterator;
            typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;
            typedef typename allocator_type::size_type                      size_type;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

        protected:
            allocator_type _alloc;
            pointer        _start;
            pointer        _end;
            pointer        _end_capacity;

        public:

            /**
             * @brief Construct a new vector object
             *
             * @param alloc allocator object
             */
            explicit vector(const allocator_type &alloc = allocator_type()) // DONE
                : _alloc(alloc),
                  _start(ft_nullptr),
                  _end(ft_nullptr),
                  _end_capacity(ft_nullptr)
            { }

            /**
             * @brief Construct a new vector object (fill)
             * with n elements. Each element is a copy of val.
             *
             * @param n Initial container size
             * @param val Value to fill the container with. Each elements will be initialized to a copy of this value.
             * @param alloc allocator object
             */
            explicit vector(size_type n, const value_type &val = value_type(),
                            const allocator_type &alloc = allocator_type()) // DONE (NEED VERIF)
                : _alloc(alloc),
                  _start(ft_nullptr),
                  _end(ft_nullptr),
                  _end_capacity(ft_nullptr)
            {

                _start        = _alloc.allocate(n);
                _end          = _start;
                _end_capacity = _start + n;
                for (; n; n--)
                {
                    _alloc.construct(_end, val);
                    _end++;
                }
            }

            /**
             * @brief Construct a new vector object (range)
             * with as many elements as the range [first,last), with each element constructed
             * from its corresponding element in that range, in the same order.
             *
             * @tparam InputIterator
             * @param first An iterator is the first value in x.
             * @param last An iterator is the last value in x.
             * @param alloc allocator object
             */
            template <class InputIterator>
            vector(InputIterator first, InputIterator last,
                   const allocator_type &alloc                                                           = allocator_type(),
                   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr) // DONE (NEED VERIF) //enable_if allows the range creation :)
                : _alloc(alloc),
                  _start(ft_nullptr),
                  _end(ft_nullptr),
                  _end_capacity(ft_nullptr)
            {

                difference_type n = ft::distance(first, last);
                _start            = _alloc.allocate(n);
                _end              = _start;
                _end_capacity     = _start + n;
                for (InputIterator tmp = first; tmp != last; tmp++)
                {
                    _alloc.construct(_end, *tmp);
                    _end++;
                }
            }

            /**
             * @brief Construct a new vector object (copy)
             * with a copy of each of the elements in x, in the same order.
             *
             * @param x vector object of the same type
             */
            vector(const vector &x) // DONE (NEED VERIF)
                : _alloc(x._alloc),
                  _start(ft_nullptr),
                  _end(ft_nullptr),
                  _end_capacity(ft_nullptr)
            {
               insert(begin(), x.begin(), x.end());
            }

            /**
             * @brief Assigns new contents to the container,
             * replacing its current contents, and modifying its size accordingly.
             *
             * @param x vector object of the same type
             * @return *this
             */
            vector &operator=(const vector &x) // DONE
            {
                if (this != &x)
                {
                    clear();
                    assign(x.begin(), x.end());
                }
                return (*this);
            }

            /**
             * @brief Destroy the vector object
             * This destroys all container elements,
             * and deallocates all the storage capacity allocated by the vector using its allocator.
             */
            ~vector() // DONE
            {
                clear();
                _alloc.deallocate(_start, capacity());
            }

            /**
             *      ITERATORS FUNCTIONS
             */

            /**
             * @brief Returns an iterator pointing to the first element in the vector.
             * If the container is empty, the returned iterator value shall not be dereferenced.
             *
             * @return iterator to the beginning of the sequence container.
             */
            iterator begin() // DONE
            {
                return (_start);
            };

            /**
             * @brief Returns an iterator pointing to the first element in the vector.
             *
             * If the container is empty, the returned iterator value shall not be dereferenced.
             * @return const_iterator to the beginning of the sequence container.
             */
            const_iterator begin() const // DONE
            {
                return (_start);
            };

            /**
             * @brief Returns an iterator referring to the past-the-end element in the vector container.
             * The past-the-end element is the theoretical element that would follow the last element
             * in the vector. It does not point to any element, and thus shall not be dereferenced.
             *
             * @return iterator to the element past the end of the sequence.
             */
            iterator end() // DONE
            {
                return (_end);
            };

            /**
             * @brief Returns an iterator referring to the past-the-end element in the vector container.
             * The past-the-end element is the theoretical element that would follow the last element
             * in the vector. It does not point to any element, and thus shall not be dereferenced.
             *
             * @return const_iterator to the element past the end of the sequence.
             */
            const_iterator end() const // DONE
            {
                return (_end);
            };

            /**
             * @brief Returns a reverse iterator pointing to the last element
             * in the vector (i.e., its reverse beginning).
             *
             * @return reverse_iterator to the reverse beginning of the sequence container.
             */
            reverse_iterator rbegin() // DONE
            {
                return reverse_iterator(end());
            };

            /**
             * @brief Returns a reverse iterator pointing to the last element
             * in the vector (i.e., its reverse beginning).
             *
             * @return const_reverse_iterator to the reverse beginning of the sequence container.
             */
            const_reverse_iterator rbegin() const // DONE
            {
                return reverse_iterator(end());
            };

            /**
             * @brief Returns a reverse iterator pointing to the theoretical element
             * preceding the first element in the vector (which is considered its reverse end).
             *
             * @return reverse_iterator to the reverse end of the sequence container.
             */
            reverse_iterator rend() // DONE
            {
                return reverse_iterator(begin());
            };

            /**
             * @brief Returns a reverse iterator pointing to the theoretical element
             * preceding the first element in the vector (which is considered its reverse end).
             *
             *
             * @return const_reverse_iterator to the reverse end of the sequence container.
             */
            const_reverse_iterator rend() const // DONE
            {
                return reverse_iterator(begin());
            };

            /**
             *      CAPACITY FUNCTIONS
             */

            /**
             * @brief This is the number of actual objects held in the vector,
             * which is not necessarily equal to its storage capacity.
             *
             * @return size_type the number of elements in the vector.
             */
            size_type size() const // DONE
            {
                return size_type(_end - _start);
            };

            /**
             * @brief This is the maximum potential size the container but the container
             * is by no means guaranteed to be able to reach that size: it can still fail
             * to allocate storage at any point before that size is reached.
             *
             * @return size_type The maximum number of elements a vector container can hold as content.
             */
            size_type max_size() const // DONE
            {
                return _alloc.max_size();
            };

            /**
             * @brief Resizes the container so that it contains n elements.
             *
             * @param n new container size, expressed in number of elements.
             * @param val value to initialize the new elements with
             */
            void resize(size_type n, value_type val = value_type()) // DONE (need verif, call insert)
            {
                if (n > max_size())
                    throw(std::length_error("ft::vector::resize"));
                else if (n > size())
                    insert(end(), n - size(), val);
                else if (n < size())
                {
                    for (; size() > n;)
                    {
                        --_end;
                        _alloc.destroy(_end);
                    }
                }
            };

            /**
             * @brief Returns the size of the storage space currently allocated for the vector,
             * expressed in terms of elements.
             *
             * @return size_type
             */
            size_type capacity() const // DONE
            {
                return _end_capacity - _start;
            };

            /**
             * @brief Returns whether the vector is empty (i.e. whether its size is 0).
             *
             * @return true / false
             */
            bool empty() const // DONE
            {
                return (size() == 0 ? true : false);
            };

            /**
             * @brief Requests that the vector capacity be at least enough to contain n elements.
             *
             * @param n minimum capacity for the vector.
             */
            void reserve(size_type n) // DONE (need verif, called in push_back)
            {
                if (n > max_size())
                {
                    throw(std::length_error("ft::vector::reserve"));
                }
                else if (capacity() < n)
                {
                    pointer         _old_start    = _start;
                    pointer         _old_end      = _end;
                    const size_type _old_capacity = capacity();

                    _start                        = _alloc.allocate(n);
                    _end                          = _start;
                    _end_capacity                 = _start + n;

                    for (pointer tmp = _old_start; tmp != _old_end; tmp++)
                    {
                        _alloc.construct(_end, *tmp);
                        _alloc.destroy(tmp);
                        _end++;
                    }
                    _alloc.deallocate(_old_start, _old_capacity);
                }
            };

            /**
             *      ELEMENT ACCESS FUNCTIONS
             */

            /**
             * @brief Returns a reference to the element at position n in the vector container.
             *
             * @param n position of an element in the container
             * @return reference to the element at the specified position in the vector.
             */
            reference operator[](size_type n) // DONE
            {
                return *(_start + n);
            };

            /**
             * @brief Returns a reference to the element at position n in the vector container.
             *
             * @param n position of an element in the container
             * @return const_reference to the element at the specified position in the vector.
             */
            const_reference operator[](size_type n) const // DONE (do not check against bounds (std::vector::at cpluspluspage))
            {
                return *(_start + n);
            };

            /**
             * @brief Returns a reference to the element at position n in the vector.
             * The function automatically checks whether n is within the bounds of valid elements
             * in the vector, throwing an out_of_range exception if it is not
             * This is in contrast with member operator[], that does not check against bounds.
             * @param n position of an element in the container
             * @return reference to the element at the specified position in the container.
             */
            reference at(size_type n) // DONE
            {
                if (n >= size())
                    throw(std::out_of_range("ft::vector::at"));
                else
                    return (*this)[n];
            };

            /**
             * @brief Returns a reference to the element at position n in the vector.
             * The function automatically checks whether n is within the bounds of valid elements
             * in the vector, throwing an out_of_range exception if it is not
             * This is in contrast with member operator[], that does not check against bounds.
             * @param n position of an element in the container
             * @return const_reference to the element at the specified position in the container.
             */
            const_reference at(size_type n) const // DONE
            {
                if (n >= size())
                    throw(std::out_of_range("ft::vector::at"));
                else
                    return (*this)[n];
            };

            /**
             * @brief Returns a reference to the first element in the vector.
             * Calling this function on an empty container causes undefined behavior.
             * @return reference to the first element in the vector
             */
            reference front() // DONE
            {
                return *begin();
            };

            /**
             * @brief Returns a reference to the first element in the vector.
             * Calling this function on an empty container causes undefined behavior.
             * @return const_reference to the first element in the vector
             */
            const_reference front() const // DONE
            {
                return *begin();
            };

            /**
             * @brief Returns a reference to the last element in the vector.
             * Calling this function on an empty container causes undefined behavior.
             * @return reference to the last element in the vector
             */
            reference back() // DONE
            {
                return *(end() - 1);
            };

            /**
             * @brief Returns a reference to the last element in the vector.
             * Calling this function on an empty container causes undefined behavior.
             * @return const_reference to the last element in the vector
             */
            const_reference back() const // DONE
            {
                return *(end() - 1);
            };

            /**
             *      MODIFIERS FUNCTIONS
             */

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
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr) // range assign // NOT FINISHED
            {
                size_type distance = ft::distance(first, last);
                clear();
                if (capacity() >= distance)
                {
                    for (; first != last; first++)
                        _alloc.construct(_end++, *first);
                }
                else
                {
                    pointer _old_start = _start;
                    const size_type _old_capacity = capacity();
                    _start                        = _alloc.allocate(distance);
                    _end                          = _start;
                    _end_capacity                 = _start + distance;

                    // for (; first != last; first++)
                    for (const_pointer tmp = &(*first); tmp != &(*last); tmp++)
                        _alloc.construct(_end++, *tmp);
                    _alloc.deallocate(_old_start, _old_capacity);
                }
            };

            /**
             * @brief Assigns new contents to the vector, replacing its current contents,
             * and modifying its size accordingly. Any elements held in the container before
             * the call are destroyed and replaced by newly constructed elements (no assignments of elements take place).
             * The new contents are n elements, each initialized to a copy of val.
             *
             * @param n new size for the container.
             * @param val value to fill the container with. Each elements will be initialized to a copy of this value.
             */
            void assign(size_type n, const value_type &val) // fill assign // DONE (need verif)
            {
                clear();
                if (capacity() >= n)
                {
                    while (n--)
                        _alloc.construct(_end++, val);
                }
                else if (n > size())
                {
                    pointer _old_start = _start;
                    const size_type _old_capacity = capacity();

                    _start                        = _alloc.allocate(n);
                    _end_capacity                 = _start + n;
                    _end                          = _start;
                    while (n--)
                        _alloc.construct(_end++, val);
                    _alloc.deallocate(_old_start, _old_capacity);
                }
            };

            /**
             * @brief Adds a new element at the end of the vector, after its current last element.
             * @param val value to be copied to the new element
             */
            void push_back(const value_type &val) // DONE (need verif with empty condition)
            {
                if (_end == _end_capacity)
                {
                    if (empty())
                        reserve(1);
                    else
                        reserve(size() * 2);
                }
                _alloc.construct(_end, val);
                ++_end;
            };

            /**
             * @brief Removes the last element in the vector,
             * effectively reducing the container size by one.
             */
            void pop_back() // DONE
            {
                --_end;
                _alloc.destroy(_end);
            };

            /**
             * @brief The vector is extended by inserting new elements before the element at the specified position,
             * effectively increasing the container size by the number of elements inserted.
             * This causes an automatic reallocation of the allocated storage space if -and only if-
             * the new vector size surpasses the current vector capacity.
             *
             * @param position Position in the vector where the new elements are inserted.
             * @param val Value to be copied (or moved) to the inserted elements.
             * @return iterator that points to the first of the newly inserted elements.
             */
            iterator insert(iterator position, const value_type &val) // single element insertion // NOT FINISHED
            {
                difference_type new_elem_index = position - begin();
                insert(position, 1, val);
                return begin() + new_elem_index;
            };

            /**
             * @brief The vector is extended by inserting new elements before the element at the specified position,
             * effectively increasing the container size by the number of elements inserted.
             * This causes an automatic reallocation of the allocated storage space if -and only if-
             * the new vector size surpasses the current vector capacity.
             *
             * @param position Position in the vector where the new elements are inserted.
             * @param n Number of elements to insert. Each element is initialized to a copy of val.
             * @param val Value to be copied (or moved) to the inserted elements.
             */
            void insert(iterator position, size_type n, const value_type &val) // fill insertion // NOT FINISHED
            {
                if (n == 0)
                    return;
                if (n > max_size())
                    throw(std::length_error("vector::insert (fill)"));
                size_type pos_len = &(*position) - _start;
                if (size_type(_end_capacity - _end) >= n)
                {
                    for (size_type i = 0; i < size() - pos_len; i++)
                        _alloc.construct(_end - i + (n - 1), *(_end - i - 1));
                    _end += n;
                    while (n)
                    {
                        _alloc.construct(&(*position) + (n - 1), val);
                        n--;
                    }
                }
                else
                {
                    pointer new_start        = pointer();
                    pointer new_end          = pointer();
                    pointer new_end_capacity = pointer();

                    int next_capacity        = (capacity() > 0) ? (int)(size() * 2) : 1;
                    new_start                = _alloc.allocate(next_capacity);
                    new_end_capacity         = new_start + next_capacity;

                    if (size_type(new_end_capacity - new_start) < size() + n)
                    {
                        if (new_start)
                            _alloc.deallocate(new_start, new_start - new_end_capacity);
                        next_capacity    = size() + n;
                        new_start        = _alloc.allocate(next_capacity);
                        new_end          = new_start + size() + n;
                        new_end_capacity = new_start + next_capacity;
                    }

                    new_end = new_start + size() + n;

                    for (int i = 0; i < (&(*position) - _start); i++)
                        _alloc.construct(new_start + i, *(_start + i));
                    for (size_type k = 0; k < n; k++)
                        _alloc.construct(new_start + pos_len + k, val);
                    for (size_type j = 0; j < (size() - pos_len); j++)
                        _alloc.construct(new_end - j - 1, *(_end - j - 1));

                    for (size_type u = 0; u < size(); u++)
                        _alloc.destroy(_start + u);
                    _alloc.deallocate(_start, capacity());

                    _start        = new_start;
                    _end          = new_end;
                    _end_capacity = new_end_capacity;
                }
            };

            /**
             * @brief The vector is extended by inserting new elements before the element at the specified position,
             * effectively increasing the container size by the number of elements inserted.
             * This causes an automatic reallocation of the allocated storage space if -and only if-
             * the new vector size surpasses the current vector capacity.
             *
             * @tparam InputIterator
             * @param position Position in the vector where the new elements are inserted.
             * @param first the first element in the range.
             * @param last the last element in the range.
             */
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr) // range insertion // NOT FINISHED
            {
                size_type dist = ft::distance(first, last);
                if (size_type(_end_capacity - _end) >= dist)
                {
                    for (size_type i = 0; i < size() - (&(*position) - _start); i++)
                        _alloc.construct(_end - i + (dist - 1), *(_end - i - 1));
                    _end += dist;
                    for (; &(*first) != &(*last); first++, position++)
                        _alloc.construct(&(*position), *first);
                }
                else
                {
                    pointer new_start        = pointer();
                    pointer new_end          = pointer();
                    pointer new_end_capacity = pointer();

                    new_start                = _alloc.allocate(size() * 2);
                    new_end                  = new_start + size() + dist;
                    new_end_capacity         = new_start + (size() * 2);

                    if (size_type(new_end_capacity - new_start) < size() + dist)
                    {
                        if (new_start)
                            _alloc.deallocate(new_start, new_end_capacity - new_start);
                        new_start        = _alloc.allocate(size() + dist);
                        new_end          = new_start + size() + dist;
                        new_end_capacity = new_end;
                    }

                    for (int i = 0; i < &(*position) - _start; i++)
                        _alloc.construct(new_start + i, *(_start + i));
                    for (int j = 0; &(*first) != &(*last); first++, j++)
                        _alloc.construct(new_start + (&(*position) - _start) + j, *first);
                    for (size_type k = 0; k < size() - (&(*position) - _start); k++)
                        _alloc.construct(new_start + (&(*position) - _start) + dist + k, *(_start + (&(*position) - _start) + k));

                    for (size_type l = 0; l < size(); l++)
                        _alloc.destroy(_start + l);
                    _alloc.deallocate(_start, capacity());

                    _start        = new_start;
                    _end          = new_end;
                    _end_capacity = new_end_capacity;
                }
            };

            /**
             * @brief Removes from the vector a single element.
             * This effectively reduces the container size by the number of elements removed, which are destroyed.
             *
             * @param position Iterator pointing to a single element to be removed from the vector.
             * @return iterator pointing to the new location of the element that followed the last element erased by the function call.
             */
            iterator erase(iterator position) // DONE (need verif)
            {
                pointer _p = &(*position); // save the adress somewhere that we will return as an it

                _alloc.destroy(&(*position));                        // destroy the desired element
                for (pointer tmp = &(*position); tmp != _end - 1; tmp++) // rebuild the elems located on the rigthside of the remove elem
                {
                    _alloc.construct(tmp, *(tmp + 1));
                    _alloc.destroy(tmp + 1);
                }
                --_end;
                return (iterator(_p));
            };

            /**
             * @brief Removes from the vector a a range of elements ([first,last)).
             * This effectively reduces the container size by the number of elements removed, which are destroyed.
             *
             * @param first the first element in the range.
             * @param last the last element in the range.
             * @return iterator pointing to the new location of the element that followed the last element erased by the function call.
             */
            iterator erase(iterator first, iterator last) // DONE (need verif)
            {
                pointer _p        = &(*first); // save the adress somewhere that we will return as an it
                pointer tmp_first = &(*first);
                pointer tmp_last  = &(*last);

                for (; tmp_first != tmp_last; tmp_first++)
                    _alloc.destroy(tmp_first); // destroy the desired element

                for (pointer tmp = &(*first); tmp_last != _end; tmp++, tmp_last++)
                {
                    _alloc.construct(tmp, *tmp_last);
                    _alloc.destroy(tmp_last);
                }
                _end -= &(*last) - &(*first);
                return (iterator(_p));
            };

            /**
             * @brief Exchanges the content of the container by the content of x, which is another
             * vector object of the same type. Sizes may differ.
             * @param x a vector of the same element and allocator types
             */
            void swap(vector &x) // DONE
            {
                if (*this != x)
                {
                    pointer        _tmp_start        = x._start;
                    pointer        _tmp_end          = x._end;
                    pointer        _tmp_end_capacity = x._end_capacity;
                    allocator_type _tmp_alloc        = x._alloc;

                    x._start                         = _start;
                    x._end                           = _end;
                    x._end_capacity                  = _end_capacity;
                    x._alloc                         = _alloc;

                    _start                           = _tmp_start;
                    _end                             = _tmp_end;
                    _end_capacity                    = _tmp_end_capacity;
                    _alloc                           = _tmp_alloc;
                }
            };

            /**
             * @brief Removes all elements from the vector (which are destroyed),
             * leaving the container with a size of 0.
             */
            void clear() // DONE
            {
                //for (size_type i = 0; i < size(); i++) //test at home worked
                size_type save_size = this->size();
				for (size_type i = 0; i < save_size; i++)
                {
                    --_end;
                    _alloc.destroy(_end);
                }
            };

            /**
             *      ALLOCATOR FUNCTIONS
             */

            /**
             * @brief Returns a copy of the allocator object associated with the vector.
             *
             * @return allocator_type
             */
            allocator_type get_allocator() const // DONE
            {
                return _alloc;
            };
    };

    /**
     *      NON-MEMBER FUNCTION OVERLOADS
     */

    template <class T, class Alloc>
    bool operator==(const ft::vector<T, Alloc> &x, const ft::vector<T, Alloc> &y) // DONE
    {
        return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
    };

    template <class T, class Alloc>
    bool operator!=(const ft::vector<T, Alloc> &x, const ft::vector<T, Alloc> &y) // DONE
    {
        return !(x == y);
    };

    template <class T, class Alloc>
    bool operator<(const ft::vector<T, Alloc> &x, const ft::vector<T, Alloc> &y) // DONE
    {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    };

    template <class T, class Alloc>
    bool operator<=(const ft::vector<T, Alloc> &x, const ft::vector<T, Alloc> &y) // DONE
    {
        return !(y < x);
    };

    template <class T, class Alloc>
    bool operator>(const ft::vector<T, Alloc> &x, const ft::vector<T, Alloc> &y) // DONE
    {
        return y < x;
    };

    template <class T, class Alloc>
    bool operator>=(const ft::vector<T, Alloc> &x, const ft::vector<T, Alloc> &y) // DONE
    {
        return !(x < y);
    };

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) // DONE
    {
        x.swap(y);
    };

} // namespace ft

#endif // !VECTOR_HPP
