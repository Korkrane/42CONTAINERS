/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_copy.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/26 17:36:07 by clorin           ###   ########.fr       */
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
	std::list<int> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(lst_size - i);

	NAMESPACE::set<int> st(lst.begin(), lst.end());
	NAMESPACE::set<int>::iterator it = st.begin(), ite = st.end();

	NAMESPACE::set<int> st_range(it, --(--ite));
	for (int i = 0; i < 5; ++i)
		st.insert(i * 5);

	it = st.begin(); ite = --(--st.end());
	NAMESPACE::set<int> st_copy(st);
	for (int i = 0; i < 7; ++i)
		st.insert(i * 7);

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(st);
	printSize(st_range);
	printSize(st_copy);

	st = st_copy;
	st_copy = st_range;
	st_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(st);
	printSize(st_range);
	printSize(st_copy);

    std::cout << "\t-- PART THREE --" << std::endl;

    NAMESPACE::set<int> st_copy2;
    st_copy2 = st_copy;
    st_copy.clear();

    printSize(st_copy);
    printSize(st_copy2);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
