/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 19:04:44 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

typedef NAMESPACE::set<char> _set;
typedef _set::const_iterator ft_const_iterator;

static unsigned int i = 0;

void	ft_comp(const _set &st, const ft_const_iterator &it1, const ft_const_iterator &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = st.key_comp()(*it1, *it2);
	res[1] = st.value_comp()(*it1, *it2);
	std::cout << "with [" << *it1 << " and " << *it2 << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
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
	_set	st;

	st.insert('a');
	st.insert('b');
	st.insert('c');
	st.insert('d');
	printSize(st);

	for (ft_const_iterator it1 = st.begin(); it1 != st.end(); ++it1)
		for (ft_const_iterator it2 = st.begin(); it2 != st.end(); ++it2)
			ft_comp(st, it1, it2);

	printSize(st);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
