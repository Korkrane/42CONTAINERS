/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/25 14:33:25 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
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
	const int size = 5;
	NAMESPACE::vector<foo> vct(size);
	NAMESPACE::vector<foo>::iterator it_0(vct.begin());
	NAMESPACE::vector<foo>::iterator it_1(vct.end());
	NAMESPACE::vector<foo>::iterator it_mid;

	NAMESPACE::vector<foo>::const_iterator cit_0 = vct.begin();
	NAMESPACE::vector<foo>::const_iterator cit_1;
	NAMESPACE::vector<foo>::const_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	print_vector(vct, 1);
	it_0 = vct.begin();
	cit_1 = vct.end();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope(it_0 + 3, it_mid);
	ft_eq_ope(it_0, it_1);
	ft_eq_ope(it_1 - 3, it_mid);
	// const it
	ft_eq_ope(cit_0 + 3, cit_mid);
	ft_eq_ope(cit_0, cit_1);
	ft_eq_ope(cit_1 - 3, cit_mid);
	// both it
	ft_eq_ope(it_0 + 3, cit_mid);
	ft_eq_ope(it_mid, cit_0 + 3);
	ft_eq_ope(it_0, cit_1);
	ft_eq_ope(it_1, cit_0);
	ft_eq_ope(it_1 - 3, cit_mid);
	ft_eq_ope(it_mid, cit_1 - 3);
}
 
    std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
