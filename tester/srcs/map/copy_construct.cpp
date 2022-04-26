/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_construct.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 15:24:53 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"
#include <list>

typedef _pair<const int, int> T;

int     main(int argc, char** argv)
{
    // argv[1] must be the output file
    if (argc < 2)
        return 1;
    std::ofstream out(argv[1]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
{
	std::list<T> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T(lst_size - i, i));

	NAMESPACE::map<int, int> mp(lst.begin(), lst.end());
	NAMESPACE::map<int, int>::iterator it = mp.begin(), ite = mp.end();

	NAMESPACE::map<int, int> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	NAMESPACE::map<int, int> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
