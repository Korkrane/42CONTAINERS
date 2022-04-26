/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_top.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/26 16:43:48 by clorin           ###   ########.fr       */
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
	NAMESPACE::stack<foo<int> > stck;

	std::cout << "Added some elements" << std::endl;
    stck.push(42);
	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);

	printSize(stck);

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

    stck.push(42);
    stck.push(24);
    std::cout << "Pop some elements" << std::endl;

    stck.pop();
    printSize(stck);
    stck.push(42);
    stck.push(24);
    std::cout << "top = " << stck.top()<< std::endl;

}
 
   std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
