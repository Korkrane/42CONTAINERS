/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:11:43 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

void	checkErase(NAMESPACE::vector<std::string> const &vct,
					NAMESPACE::vector<std::string>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	print_vector(vct);
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
	NAMESPACE::vector<std::string> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	print_vector(vct);

	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back("Hello");
	vct.push_back("Hi there");
	print_vector(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	print_vector(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
