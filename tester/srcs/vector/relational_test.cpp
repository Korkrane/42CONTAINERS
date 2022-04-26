/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:38:49 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

template <class T, class Alloc>
void	cmp(const NAMESPACE::vector<T, Alloc> &lhs, const NAMESPACE::vector<T, Alloc> &rhs)
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
	NAMESPACE::vector<int> vct(4);
	NAMESPACE::vector<int> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
