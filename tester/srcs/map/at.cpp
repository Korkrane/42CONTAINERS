/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 16:23:58 by clorin           ###   ########.fr       */
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
	NAMESPACE::map<char, foo<std::string> > mp;

	mp['a'] = "an element";
	mp['b'] = "another element";
	mp['c'] = mp['b'];
	mp['b'] = "old element";

	printSize(mp);

	std::cout << "insert a new element via operator[]: " << mp['d'] << std::endl;

	printSize(mp);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
