/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirect_iterator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:09:04 by clorin           ###   ########.fr       */
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
	std::list<int>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	NAMESPACE::vector<int> vct(lst.begin(), lst.end());
	print_vector(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	print_vector(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	print_vector(vct);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
