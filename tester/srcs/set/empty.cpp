/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 18:35:21 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"
#include <list>

template <class T>
void	is_empty(T const &st)
{
	std::cout << "is_empty: " << st.empty() << std::endl;
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
	std::list<char> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('a' + i);

	NAMESPACE::set<char> st(lst.begin(), lst.end()), st2;
	NAMESPACE::set<char>::iterator it;

	lst.clear();
	is_empty(st);
	printSize(st);

	is_empty(st2);
	st2 = st;
	is_empty(st2);

	it = st.begin();
	for (unsigned long int i = 3; i < 6; ++i)
		st.insert(i * 7);

	printSize(st);
	printSize(st2);

	st2.clear();
	is_empty(st2);
	printSize(st2);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
