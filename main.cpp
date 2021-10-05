/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:32:14 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/05 18:58:09 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <memory> //std::allocator

#include "./utility.hpp"
#include "./algorithm.hpp"
#include "./type_traits.hpp"
#include <algorithm> // std::equal
#include <vector>	 // std::vector
#include <string>	 // std::string

void test_utility_ftequal()
{
	std::cout << "ft_test.\n";
	int myints[] = {20, 40, 60, 80, 100};		   //   myints: 20 40 60 80 100
	std::vector<int> myvector(myints, myints + 5); // myvector: 20 40 60 80 100

	// using default comparison:
	if (ft::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3] = 81; // myvector: 20 40 60 81 100

	// using default comparison:
	if (ft::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
}

void test_utility_equal()
{
	int myints[] = {20, 40, 60, 80, 100};		   //   myints: 20 40 60 80 100
	std::vector<int> myvector(myints, myints + 5); // myvector: 20 40 60 80 100

	// using default comparison:
	if (std::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3] = 81; // myvector: 20 40 60 81 100

	// using default comparison:
	if (std::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
}

void test_utility_lexico()
{
	std::string mystrings[] = {"One", "Two", "Three"};
	std::string mystrings2[] = {"one", "two", "three"};

	std::vector<std::string> v1(mystrings, mystrings + 3);
	std::vector<std::string> v2(mystrings2, mystrings2 + 3);
	bool result;

	result = std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

	if (result == true)
		std::cout << "v1 is less than v2." << std::endl;

	v1[0] = "two";

	result = std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

	if (result == false)
		std::cout << "v1 is not less than v2." << std::endl;
}

void test_utility_ftlexico()
{
	std::string mystrings[] = {"One", "Two", "Three"};
	std::string mystrings2[] = {"one", "two", "three"};

	std::vector<std::string> v1(mystrings, mystrings + 3);
	std::vector<std::string> v2(mystrings2, mystrings2 + 3);
	bool result;

	result = ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

	if (result == true)
		std::cout << "v1 is less than v2." << std::endl;

	v1[0] = "two";

	result = ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

	if (result == false)
		std::cout << "v1 is not less than v2." << std::endl;
}

int main()
{
	test_utility_equal();
	test_utility_ftequal();
	test_utility_lexico();
	test_utility_ftlexico();
	return (0);
}
