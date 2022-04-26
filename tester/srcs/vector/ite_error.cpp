/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ite_error.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 21:47:31 by clorin           ###   ########.fr       */
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
	const int size = 5;
	NAMESPACE::vector<int> vct(size);
	NAMESPACE::vector<int>::iterator it = vct.begin();
	NAMESPACE::vector<int>::const_iterator ite = vct.begin();

	for (int i = 0; i < size; ++i)
		it[i] = i;

	*ite = 42; // < -- error

}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
