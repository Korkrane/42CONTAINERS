/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 15:06:10 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

int     main(int argc, char** argv)
{
    // argv[1] must be the output file
    if (argc < 2)
        return 1;
    std::ofstream out(argv[1]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
{
	NAMESPACE::vector<int> foo(3, 15);
	NAMESPACE::vector<int> bar(5, 42);
	
	NAMESPACE::vector<int>::const_iterator it_foo = foo.begin();
	NAMESPACE::vector<int>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	print_vector(foo);
	std::cout << "bar contains:" << std::endl;
	print_vector(bar);

	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	print_vector(foo);
	std::cout << "bar contains:" << std::endl;
	print_vector(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
