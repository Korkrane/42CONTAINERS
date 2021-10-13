/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:23:19 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/13 17:04:14 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#define BLACK false
#define RED   true

#include <iostream>

namespace ft
{
    /**
     * @brief data structure that represents a node in the tree
     *
     */
    struct node
    {
            int _color;
            node *_parent;
            node *_left;
            node *_right;
            int _data;
    };

    typedef node *NodePtr;

    class rbtree
    {
        private:
            NodePtr root;

            void initializeNULLNode(NodePtr node, NodePtr parent)
            {
                node->_data   = 0;
                node->_parent = parent;
                node->_left   = nullptr;
                node->_right  = nullptr;
                node->_color  = 0;
            }
    };
} // namespace ft

#endif // !RBTREE_HPP