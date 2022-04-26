/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:35:17 by clorin           ###   ########.fr       */
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
	NAMESPACE::vector<std::string> vct(8);
	NAMESPACE::vector<std::string> vct2;
	NAMESPACE::vector<std::string>::iterator it = vct.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		it[i] = std::string((vct.size() - i), i + 65);
	print_vector(vct, true);

	std::cout << "push_back():\n" << std::endl;

	vct.push_back("One long string");
	vct2.push_back("Another long string");

	print_vector(vct);
	print_vector(vct2);

	vct.pop_back();
	vct2.pop_back();

	print_vector(vct);
	print_vector(vct2);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
