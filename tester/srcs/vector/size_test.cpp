/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:46:19 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

void	is_empty(NAMESPACE::vector<int> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
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
	const int start_size = 7;
	NAMESPACE::vector<int> vct(start_size, 20);
	NAMESPACE::vector<int> vct2;
	NAMESPACE::vector<int>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	print_vector(vct, true);

	vct.resize(10, 42);
	print_vector(vct, true);

	vct.resize(18, 43);
	print_vector(vct, true);
	vct.resize(10);
	print_vector(vct, true);
	vct.resize(23, 44);
	print_vector(vct, true);
	vct.resize(5);
	print_vector(vct, true);
	vct.reserve(5);
	vct.reserve(3);
	print_vector(vct, true);
	vct.resize(87);
	vct.resize(5);
	print_vector(vct, true);

	is_empty(vct2);
	vct2 = vct;
	is_empty(vct2);
	vct.reserve(vct.capacity() + 1);
	print_vector(vct, true);
	print_vector(vct2, true);

	vct2.resize(0);
	is_empty(vct2);
	print_vector(vct2, true);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
