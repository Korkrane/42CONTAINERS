/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rite.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 16:51:43 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"
#include <list>

typedef _pair<const char, int> T3;
typedef _pair<const float, foo<int> > T4;

int     main(int argc, char** argv)
{
    // argv[1] must be the output file
    if (argc < 2)
        return 1;
    std::ofstream out(argv[1]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
{
    NAMESPACE::map<int, int> mp;
	NAMESPACE::map<int, int>::iterator it = mp.begin();
	NAMESPACE::map<int, int>::const_iterator cit = mp.begin();

	NAMESPACE::map<int, int>::reverse_iterator rit(it);

	NAMESPACE::map<int, int>::const_reverse_iterator crit(rit);
	NAMESPACE::map<int, int>::const_reverse_iterator crit_(it);
	NAMESPACE::map<int, int>::const_reverse_iterator crit_2(cit);
}
{
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, (i + 1) * 7));

	NAMESPACE::map<char, int> mp(lst.begin(), lst.end());
	NAMESPACE::map<char, int>::iterator it_ = mp.begin();
	NAMESPACE::map<char, int>::reverse_iterator it(it_), ite;
	printSize(mp);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == dec(it, 3).base()) << std::endl;

	printPair(it.base());
	printPair(inc(it.base(), 1));

	std::cout << "TEST OFFSET" << std::endl;
	--it;
	printPair(it);
	printPair(it.base());

	it = mp.rbegin(); ite = mp.rend();
	while (it != ite)
		std::cout << "[rev] " << printPair(it++, false) << std::endl;
	printReverse(mp);

}

{
    	std::list<T4> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T4(2.5 - i, (i + 1) * 7));

	NAMESPACE::map<float, foo<int> > mp(lst.begin(), lst.end());
	NAMESPACE::map<float, foo<int> >::reverse_iterator it(mp.rbegin());
	NAMESPACE::map<float, foo<int> >::const_reverse_iterator ite(mp.rbegin());
	printSize(mp);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->second.m();
	ite->second.m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).second.m();
	(*ite).second.m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);
}
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
