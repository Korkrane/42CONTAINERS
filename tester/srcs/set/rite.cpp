/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rite.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 18:50:35 by clorin           ###   ########.fr       */
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
	std::list<foo<int> > lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back((i + 1) * 7);

	NAMESPACE::set<foo<int> > st(lst.begin(), lst.end());
	NAMESPACE::set<foo<int> >::reverse_iterator it(st.rbegin());
	NAMESPACE::set<foo<int> >::const_reverse_iterator ite(st.rbegin());
	printSize(st);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->m();
	ite->m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).m();
	(*ite).m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);

}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
