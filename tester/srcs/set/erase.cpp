/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 18:42:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"
#include <list>

static int iter = 0;

template <typename SET, typename U>
void	ft_erase(SET &st, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param);
	printSize(st);
}

template <typename SET, typename U, typename V>
void	ft_erase(SET &st, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param, param2);
	printSize(st);
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
	std::list<std::string> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::string((lst_size - i), i + 65));
	NAMESPACE::set<std::string> st(lst.begin(), lst.end());
	printSize(st);

	ft_erase(st, ++st.begin());

	ft_erase(st, st.begin());
	ft_erase(st, --st.end());

	ft_erase(st, st.begin(), ++(++(++st.begin())));
	ft_erase(st, --(--(--st.end())), --st.end());

	st.insert("Hello");
	st.insert("Hi there");
	printSize(st);
	ft_erase(st, --(--(--st.end())), st.end());

	st.insert("ONE");
	st.insert("TWO");
	st.insert("THREE");
	st.insert("FOUR");
	printSize(st);
	ft_erase(st, st.begin(), st.end());}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
