/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ite_error.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/27 19:52:10 by clorin           ###   ########.fr       */
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
	NAMESPACE::set<int> st;

	NAMESPACE::set<int>::const_iterator ite = st.begin();
	*ite = 42; // < -- error expected
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
