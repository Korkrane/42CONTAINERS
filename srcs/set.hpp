/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:12:44 by clorin            #+#    #+#             */
/*   Updated: 2021/11/23 14:59:03 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "bidirectional_iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator.hpp"
#include "RBTree.hpp"
#include "pair.hpp"     //to selectKey()
#include "utils/algorithmes.hpp"
#include <iostream>

namespace ft
{
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set
    {
        public:

            typedef T                                       key_type;
            typedef T                                       value_type;
            typedef Compare                                 key_compare;
            typedef Alloc                                   allocator_type;
            typedef typename Alloc::reference               reference;
            typedef typename Alloc::const_reference         const_reference;
            typedef typename Alloc::pointer                 pointer;
            typedef typename Alloc::const_pointer           const_pointer;
            typedef typename std::size_t			        size_type;
            typedef Node<value_type>                        node_type;
            typedef node_type*                              node_ptr;

            typedef typename ft::bidirectional_iterator<const value_type, const node_type>  iterator;
            typedef typename ft::bidirectional_iterator<const value_type, const node_type>  const_iterator;
            typedef typename ft::reverse_iterator<iterator> 				                reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			                const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type	               difference_type;
			
            typedef ft::RBTree<key_type, value_type, selectKey<value_type, key_type>, key_compare>  tree_type;

            class                                                           value_compare;
            
            /*********** constructors **************/
            //default
            explicit set(const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()):_alloc(alloc), _comp(comp), _tree(){}
            
            //range(2)
            template <class InputIterator>
            set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()):_alloc(alloc), _comp(comp), _tree()
            {
                    insert(first, last);
            }

            //copy(3)
            set (const set &x):_alloc(x._alloc), _comp(x._comp), _tree()
            {
                insert(x.begin(), x.end());
            }

            virtual ~set(){}

            set &operator=(const set &cpy)
            {
                if (this != &cpy)
                {
                    clear();
                    _alloc = cpy._alloc;
                    _comp = cpy._comp;
                    insert(cpy.begin(), cpy.end());
                }
                return *this;
            }

            /***************** Iterators ****************/
            iterator        begin()
            {
                // return first element so the min key value
                return (iterator(_tree.min(),_tree.getRoot(), _tree.getNill()));
            }

            const_iterator  begin() const
            {
                return (const_iterator(_tree.min(), _tree.getRoot(), _tree.getNill()));
            }
            
            iterator        end()
            {
                return (iterator(_tree.getNill(), _tree.getRoot(), _tree.getNill()));
            }

            const_iterator  end() const
            {
                return (const_iterator(_tree.getNill(), _tree.getRoot(), _tree.getNill()));
            }

            reverse_iterator        rbegin()        {return(reverse_iterator(end()));}
            const_reverse_iterator  rbegin() const  {return (const_reverse_iterator(end()));}

            reverse_iterator        rend()          {return(reverse_iterator(begin()));}
            const_reverse_iterator  rend() const    {return(const_reverse_iterator(begin()));}

            /*  ********************** Capacity ***********************/
            
            bool            empty() const       {return (_tree.getSize() == 0);}
            size_type       size() const        {return _tree.getSize();}
            size_type       max_size() const    {return _tree.max_size();}

             /*  *********************    Modifiers   ***************** */

             //single element (1)
            pair<iterator, bool>    insert(const value_type &val)
            {
                bool        succes = _tree.insert(val);
                iterator    it = find(val);
                return (ft::pair<iterator, bool>(it, succes));
            }
            
            //with hint (2)
            iterator                insert(iterator position, const value_type &val)
            {
                (void) position;
                return (insert(val).first);
            }

            // range(3)
            template <class InputIterator>
            void                    insert(InputIterator first, InputIterator last)
            {
                while(first != last)
                    _tree.insert(*(first++));
            }

            //(1)
            void                    erase(iterator position)
            {
                erase(*position);
            }

            //(2)
            size_type               erase(const value_type &val)
            {
                if(_tree.deleteNode(val))
                    return 1;
                else return 0;   
            }

            //(3)
            void                    erase(iterator first, iterator last)
            {
                while(first != last)
                    erase(first++);
            }

            void                    clear()
            {
                erase(begin(), end());
            
            }

            void                        swap(set &x)
            {
                _tree.swap(x._tree);
            }
            
            /************************   Observers ***********************/

            key_compare     key_comp() const {return _comp;}
            value_compare   value_comp() const {return value_compare(_comp); }

            /************************ Operations *****************************/
            iterator            find(const value_type &val) const
            {
                node_ptr  node  = _tree.search(val);
                if (node == _tree.getNill())
                    return (end());
                return (iterator(node, _tree.getRoot(), _tree.getNill()));
            }
            
            size_type           count(const value_type &val) const
            {
                node_ptr    node = _tree.search(val);
                if (node == _tree.getNill())
                    return 0;
                return 1;                
            }
            
            iterator            lower_bound(const key_type &val) const
            {
                iterator    it = begin();
                while(it != end())
                {
                    if (_comp(*it, val) == false)
                        break;
                    it++;
                }
                return (it);
            }

            iterator            upper_bound(const key_type &val) const
            {
                iterator    it = begin();
                while(it != end())
                {
                    if (_comp(val, *it) == true)
                        break;
                    it++;
                }
                return (it);
            }

            pair<iterator, iterator>    equal_range(const key_type &k) const
            {
                return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
            }
            
            /*************************** Allocator ***************************/

            allocator_type      get_allocator() const {return _alloc;}
            
        private:
            allocator_type      _alloc;
            key_compare         _comp;
            tree_type           _tree;


    };

    /*      *********** operators relational ***********************/
    // equal
    template <class T, class Compare, class Alloc>
    bool    operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    // !=   
    template <class T, class Compare, class Alloc>
    bool    operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (!(lhs == rhs));
    }

    // < 
    template <class T, class Compare, class Alloc>
    bool    operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Compare, class Alloc>
    bool    operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        //a>b		<==>  b<a
		return (rhs < lhs);
    }

    template <class T, class Compare, class Alloc>
    bool    operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        //a<=b	->	!(b < a)
		return (!(rhs < lhs));
    }

    template <class T, class Compare, class Alloc>
    bool    operator>=(const set< T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        //a>=b	->	!(a<b)
		return (!(lhs < rhs));
    }


    /*      *********** Non-member overload functions ***********/

    template <class T, class Compare, class Alloc>
    void    swap(set<T, Compare, Alloc> &x, set<T, Compare, Alloc> &y)
    {
        x.swap(y);
    }

    template <class T, class Compare, class Alloc>
    class set<T,Compare,Alloc>::value_compare
    {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        // see https://www.cplusplus.com/reference/map/map/value_comp/
        friend class set;
        
        protected:
            Compare comp;
             value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
        
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const
            {
                return comp(x, y);
            }
    };

} // ft
#endif