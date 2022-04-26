/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_find_count.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 18:46:10 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

NAMESPACE::set<int> st;
NAMESPACE::set<int>::iterator it = st.end();

void	ft_find(int const &k)
{
	NAMESPACE::set<int>::iterator ret = st.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "set::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(int const &k)
{
	std::cout << "set::count(" << k << ")\treturned [" << st.count(k) << "]" << std::endl;
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
	st.insert(42);
	st.insert(25);
	st.insert(80);
	st.insert(12);
	st.insert(27);
	st.insert(90);
	printSize(st);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(12);
	ft_find(3);
	ft_find(35);
	ft_find(90);
	ft_find(100);

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3);
	ft_count(12);
	ft_count(3);
	ft_count(35);
	ft_count(90);
	ft_count(100);

	st.erase(st.find(27));

	printSize(st);

	NAMESPACE::set<int> const c_set(st.begin(), st.end());
	std::cout << "const set.find(" << 42 << ")->second: [" << *(c_set.find(42)) << "]" << std::endl;
	std::cout << "const set.count(" << 80 << "): [" << c_set.count(80) << "]" << std::endl;
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
