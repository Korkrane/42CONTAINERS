/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 19:07:08 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

template <class SET>
void	cst(const SET &lhs, const SET &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int     main(int argc, char** argv)
{
    // argv[1] must be the output file
    if (argc < 2)
        return 1;
    std::ofstream out(argv[1]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
{
	NAMESPACE::set<char> st1;
	NAMESPACE::set<char> st2;

	st1.insert('a');
	st1.insert('b');
	st1.insert('c');
	st1.insert('d');
	st2.insert('a');
	st2.insert('b');
	st2.insert('c');
	st2.insert('d');

	cst(st1, st1); // 0
	cst(st1, st2); // 1

	st2.insert('e');
	st2.insert('f');
	st2.insert('h');
	st2.insert('h');

	cst(st1, st2); // 2
	cst(st2, st1); // 3

	swap(st1, st2);

	cst(st1, st2); // 4
	cst(st2, st1); // 5
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
