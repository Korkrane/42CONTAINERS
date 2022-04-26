/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rite01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:41:38 by clorin           ###   ########.fr       */
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
	const int size = 5;
	NAMESPACE::vector<foo> vct(size);
	NAMESPACE::vector<foo>::reverse_iterator it(vct.rbegin());
	NAMESPACE::vector<foo>::const_reverse_iterator ite(vct.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);
	print_vector(vct, 1);

	it = vct.rbegin();
	ite = vct.rbegin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
