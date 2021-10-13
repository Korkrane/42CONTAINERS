/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:34:39 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/13 14:29:11 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "algorithm.hpp" //lexico_compar
#include "iterator.hpp"  //reverse_it
#include "random_access_iterator.hpp"
#include <memory>

namespace ft
{
    //clang-format off
    template <class T, class Alloc = std::allocator<T>>
    //clang-format on
    class vector
    {
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::random_access_iterator<T> iterator;
            typedef typename ft::random_access_iterator<const T> const_iterator;
            typedef typename ft::reverse_iterator<T> reverse_iterator;
            typedef typename ft::reverse_iterator<const T> const_reverse_iterator;
            typedef typename allocator_type::size_type size_type;
            typedef typename allocator_type::difference_type difference_type;

        protected:
            pointer _start;
            pointer _end;
            pointer _end_capacity;
            allocator_type _alloc;

        public:
            explicit vector(const allocator_type &alloc = allocator_type()) // default ctor //DONE
                : _alloc(alloc),
                  _start(nullptr),
                  _end(nullptr),
                  _end_capacity(nullptr)
            { }

            explicit vector(size_type n, const value_type &val = value_type(),
                            const allocator_type &alloc = allocator_type()) // fill ctor //DONE (NEED VERIF)
                : _alloc(alloc),
                  _start(nullptr),
                  _end(nullptr),
                  _end_capacity(nullptr)
            {
                _start        = _alloc.allocate(n);
                _end          = _start;
                _end_capacity = _start + n;
                for (; n > 0; n--)
                {
                    _alloc.construct(_end, val);
                    _end++;
                }
            }

            template <class InputIterator>
            vector(InputIterator first, InputIterator last,
                   const allocator_type &alloc = allocator_type()) // range ctor //DONE (NEED VERIF)
                : _alloc(alloc),
                  _start(nullptr),
                  _end(nullptr),
                  _end_capacity(nullptr)
            {
                difference_type n = ft::distance(first, last);
                _start            = _alloc.allocate(n);
                _end              = _start;
                _end_capacity     = _start + n;
                for (; first != last; first++)
                {
                    _alloc.construct(_end, *first);
                    _end++;
                }
            }

            vector(const vector &x) // copy ctor //DONE (NEED VERIF)
                : _alloc(x._alloc),
                  _start(nullptr),
                  _end(nullptr),
                  _end_capacity(nullptr)
            {
                difference_type n  = x._end - x._start;
                _start             = _alloc.allocate(n);
                _end               = _start;
                iterator tmp_start = x._start;
                iterator tmp_end   = x._end;
                for (; tmp_start != tmp_end; tmp_start++)
                {
                    _alloc.construct(_end, *tmp_start);
                    _end++;
                }
                _end_capacity = _end;
            }

            vector &operator=(const vector &x) // DONE
            {
                if (this != &x)
                {
                    this->clear();
                    this->assign(x.begin(), x.end());
                }
                return (*this);
            }

            ~vector() // dtor // DONE
            {
                this->clear();
                _alloc.deallocat(_start, this->capacity());
            }

            /// ***iterators***

            iterator begin() // DONE
            {
                return iterator(_start);
            };

            const_iterator begin() const // DONE
            {
                return const_iterator(_start);
            };

            iterator end() // DONE
            {
                return iterator(_end);
            };

            const_iterator end() const // DONE
            {
                return const_iterator(_end);
            };

            reverse_iterator rbegin() // DONE
            {
                return reverse_iterator(begin());
            };

            const_reverse_iterator rbegin() const // DONE
            {
                return const_reverse_iterator(begin());
            };

            reverse_iterator rend() // DONE
            {
                return reverse_iterator(end());
            };

            const_reverse_iterator rend() const // DONE
            {
                return const_reverse_iterator(end());
            };

            /// ***capacity***

            size_type size() const // DONE
            {
                return size_type(_end - _start);
            };

            size_type max_size() const // DONE
            {
                return _alloc.max_size();
            };

            void resize(size_type n, value_type val = value_type()) // DONE (need verif, call insert)
            {
                if (n > this->max_size())
                    throw(std::length_error("ft::vector::resize"));
                else if (n > this->size())
                    insert(end(), n - size(), val);
                else if (n < this->size())
                {
                    for (; this->size() > n; n++)
                    {
                        --_end;
                        _alloc.destroy(_end);
                    }
                }
            };

            size_type capacity() const // DONE
            {
                return _end_capacity - _start;
            };

            bool empty() const // DONE
            {
                return begin() == end();
            };

            void reserve(size_type n) // DONE (need verif, called in push_back)
            {
                if (n > this->max_size())
                {
                    throw(std::length_error("ft::vector::reserve"))
                }
                else if (this->capacity() < n)
                {
                    pointer _old_start            = _start;
                    pointer _old_end              = _end;
                    const size_type _old_capacity = capacity();

                    _start                        = _alloc.allocate(n);
                    _end                          = _start;
                    _end_capacity                 = _start + n;

                    for (pointer tmp = _old_start; tmp != _old_end; tmp++)
                    {
                        _alloc.construct(_end, *tmp);
                        _end++;
                        _alloc.destroy(tmp);
                    }
                    _alloc.deallocate(_old_start, _old_capacity);
                }
            };

            /// ***element access***

            reference operator[](size_type n) // DONE
            {
                return *_start + n;
            };

            const_reference operator[](size_type n) const // DONE (do not check against bounds (std::vector::at cpluspluspage))
            {
                return *_start + n;
            };

            reference at(size_type n) // DONE
            {
                if (n >= this->size())
                    throw(std::out_of_range("ft::vector::at"));
                else
                    return (*this)[n];
            };

            const_reference at(size_type n) const // DONE
            {
                if (n >= this->size())
                    throw(std::out_of_range("ft::vector::at"));
                else
                    return (*this)[n];
            };

            reference front() // DONE
            {
                return *begin();
            };

            const_reference front() const // DONE
            {
                return *begin();
            };

            reference back() // DONE
            {
                return *(end() - 1);
            };

            const_reference back() const // DONE
            {
                return *(end() - 1);
            };

            /// ***modifiers***

            template <class InputIterator>
            void assign(InputIterator first, InputIterator last) // range assign // NOT FINISHED
            {
                clear();
                /*
                pointer _tmp = _start;
                for (; first != last && _tmp != _end; ++_tmp, ++first)
                {
                    *_tmp = *first;
                }
                if (first == last)
                {
                }
                else
                {
                }
                */
            };

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
                    pointer _old_start            = _start;
                    pointer _old_end_capacity     = _end_capacity;
                    const size_type _old_capacity = capacity();

                    _start                        = _alloc.allocate(n);
                    _end_capacity                 = _start + n;
                    _end                          = _start;
                    while (n--)
                        _alloc.construct(_end++, val);
                    _alloc.deallocate(_old_start, _old_capacity);
                }
            };

            void push_back(const value_type &val) // DONE (need verif with empty condition)
            {
                if (_end != _end_capacity)
                {
                    _alloc.construct(_end, val);
                    ++_end;
                }
                else
                {
                    if (empty())
                        reserve(1);
                    else
                        reserve(size() * 2);
                }
            };

            void pop_back() // DONE
            {
                --_end;
                _alloc.destroy(_end);
            };

            iterator insert(iterator position, const value_type &val) // single element insertion // NOT FINISHED
                {};

            void insert(iterator position, size_type n, const value_type &val) // fill insertion // NOT FINISHED
                {};

            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last) // range insertion // NOT FINISHED
                {};

            iterator erase(iterator position) // NOT FINISHED
                {};

            iterator erase(iterator first, iterator last) // NOT FINISHED
                {};

            void swap(vector &x) // DONE
            {
                if (*this != x)
                {
                    pointer _tmp_start        = x._start;
                    pointer _tmp_end          = x._end;
                    pointer _tmp_end_capacity = x._end_capacity;
                    allocator_type _tmp_alloc = x._alloc;

                    x._start                  = _start;
                    x._end                    = _end;
                    x._end_capacity           = _end_capacity;
                    x._alloc                  = _alloc;

                    _start                    = _tmp_start;
                    _end                      = _tmp_end;
                    _end_capacity             = _tmp_end_capacity;
                    _alloc                    = _tmp_alloc;
                }
            };

            void clear() // DONE
            {
                for (size_type i = 0; i < size(); i++)
                {
                    --_end;
                    _alloc.destroy(_end);
                }
            };

            /// ***allocator***

            allocator_type get_allocator() const // DONE
            {
                return _alloc;
            };
    };

    /// ***Non-member function overloads***

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
