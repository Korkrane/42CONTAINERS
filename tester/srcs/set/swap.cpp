/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 19:12:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"
#include <list>

int     main(int argc, char** argv)
{
    // argv[1] must be the output file
    if (argc < 2)
        return 1;
    std::ofstream out(argv[1]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
{
	std::list<char> lst;

	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('a' + i);
	NAMESPACE::set<char> foo(lst.begin(), lst.end());

	lst.clear(); lst_size = 4;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('z' - i);
	NAMESPACE::set<char> bar(lst.begin(), lst.end());

	NAMESPACE::set<char>::const_iterator it_foo = foo.begin();
	NAMESPACE::set<char>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	foo.swap(bar);

	std::cout << "AFTER SWAP in member's function" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;

    std::cout << "**** TEST with non member's function ***" << std::endl;

    std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

    NAMESPACE::swap(bar,foo);

    std::cout << "AFTER SWAP with function swap(x,y)" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
