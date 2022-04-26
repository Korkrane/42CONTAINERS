/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 13:28:27 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

int     main(int argc, char** argv)
{
  (void)argv;
    // argv[1] must be the output file
    if (argc < 2)
    {
        std::cerr << "error no output file" << std::endl;
        return 1;
    }
    std::ofstream out(argv[1]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
    
	NAMESPACE::vector<int> vct(5);
	NAMESPACE::vector<int>::iterator it = vct.begin(), ite = vct.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	NAMESPACE::vector<int> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	NAMESPACE::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
  std::cout << "vct"<<std::endl;
	print_vector(vct, true);
  std::cout << "vct_range" << std::endl;
	print_vector(vct_range, true);
  std::cout << "vct_copy" << std::endl;
	print_vector(vct_copy, true);

  std::cout << "vct = vct_copy" << std::endl;
	vct = vct_copy;
  std::cout << "vct_copy = vct_range"<< std::endl;
	vct_copy = vct_range;
  std::cout << "vct.range()"<< std::endl;
	vct_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
  std::cout << "vct" << std::endl;
	print_vector(vct, true);
  std::cout << "vct_range" << std::endl;
	print_vector(vct_range, true);
  std::cout << "vct_copy" << std::endl;
	print_vector(vct_copy, true);

	std::cout << "\t-- PART THREE --" << std::endl;
	NAMESPACE::vector<int> copy(vct);	//copy by construct
	print_vector(copy, true);
/******************************************************************************************/

    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
