/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:20:47 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/
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
	NAMESPACE::vector<int> vct(10);
	NAMESPACE::vector<int> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	print_vector(vct);
    /*
    single element (1)
	    iterator insert (iterator position, const value_type& val);*/
	vct2.insert(vct2.end(), 42);

    /*fill (2)
    void insert (iterator position, size_type n, const value_type& val);*/
	vct2.insert(vct2.begin(), 2, 21);
	print_vector(vct2);

	vct2.insert(vct2.end() - 2, 42);
	print_vector(vct2);

	vct2.insert(vct2.end(), 2, 84);
	print_vector(vct2);

	vct2.resize(4);
	print_vector(vct2);
    
    /*range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);*/
	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	print_vector(vct2);

	print_vector(vct);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
