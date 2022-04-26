/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/26 16:15:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

#define TESTED_TYPE foo<int>
#define t_stack_ NAMESPACE::stack<TESTED_TYPE>
typedef t_stack_::container_type container_type;

int     main(int argc, char** argv)
{
    // argv[1] must be the output file
    if (argc < 2)
        return 1;
    std::ofstream out(argv[1]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_		stck(ctnr);

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);

	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	printSize(stck);
    t_stack_        copy2=stck;
    	std::cout << "empty: " << copy2.empty() << std::endl;
	std::cout << "size: " << copy2.size() << std::endl;

    copy2.push(7);
    printSize(stck);
    printSize(copy2);

}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
