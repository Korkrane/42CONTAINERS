/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rite_error.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 22:23:48 by clorin           ###   ########.fr       */
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
    NAMESPACE::vector<int> vct;
	NAMESPACE::vector<int>::iterator it = vct.begin();
	NAMESPACE::vector<int>::const_iterator cit = vct.begin();

	NAMESPACE::vector<int>::reverse_iterator rit(it);

	NAMESPACE::vector<int>::const_reverse_iterator crit(rit);

	// erros expected because no contructors
	NAMESPACE::vector<int>::reverse_iterator rit_(crit);
	NAMESPACE::vector<int>::reverse_iterator rit2(cit);
	NAMESPACE::vector<int>::iterator it2(rit);
	NAMESPACE::vector<int>::const_iterator cit2(crit);
	
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
