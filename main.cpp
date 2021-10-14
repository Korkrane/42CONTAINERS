/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:32:14 by bahaas            #+#    #+#             */
/*   Updated: 2021/10/14 19:16:15 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory> //std::allocator

#include "./algorithm.hpp"
#include "./iterator.hpp"
//#include "./map.hpp"
//#include "./stack.hpp"
#include "./type_traits.hpp"
#include "./utility.hpp"
#include "./vector.hpp"
#include <algorithm> // std::equal
#include <map>       //std::map
#include <stack>     // std::stack
#include <string>    // std::string
#include <vector>    // std::vector

void test_utility_ftequal()
{
    std::cout << "ft_test.\n";
    int              myints[] = {20, 40, 60, 80, 100}; //   myints: 20 40 60 80 100
    std::vector<int> myvector(myints, myints + 5);     // myvector: 20 40 60 80 100

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
    int              myints[] = {20, 40, 60, 80, 100}; //   myints: 20 40 60 80 100
    std::vector<int> myvector(myints, myints + 5);     // myvector: 20 40 60 80 100

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
    std::string mystrings[]  = {"One", "Two", "Three"};
    std::string mystrings2[] = {"one", "two", "three"};

    std::vector<std::string> v1(mystrings, mystrings + 3);
    std::vector<std::string> v2(mystrings2, mystrings2 + 3);
    bool                     result;

    result = std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

    if (result == true)
        std::cout << "v1 is less than v2." << std::endl;

    v1[0]  = "two";

    result = std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

    if (result == false)
        std::cout << "v1 is not less than v2." << std::endl;
}

void test_utility_ftlexico()
{
    std::string mystrings[]  = {"One", "Two", "Three"};
    std::string mystrings2[] = {"one", "two", "three"};

    std::vector<std::string> v1(mystrings, mystrings + 3);
    std::vector<std::string> v2(mystrings2, mystrings2 + 3);
    bool                     result;

    result = ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

    if (result == true)
        std::cout << "v1 is less than v2." << std::endl;

    v1[0]  = "two";

    result = ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

    if (result == false)
        std::cout << "v1 is not less than v2." << std::endl;
}

void std_vec()
{
    using namespace std;

    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();
    /*
        // resizes the vector size to 4
        g1.resize(4);

        // prints the vector size after resize()
        cout << "\nSize : " << g1.size();

        // checks if the vector is empty or not
        if (g1.empty() == false)
            cout << "\nVector is not empty";
        else
            cout << "\nVector is empty";

        cout << "\nVector elements are: ";
        for (auto it = g1.begin(); it != g1.end(); it++)
            cout << *it << " ";
        cout << endl;
    */
    return;
}

void ft_vec()
{
    ft::vector<int> g1;

    // for (int i = 1; i <= 5; i++)
    //   g1.push_back(i);

    /*
        std::cout << "Size : " << g1.size();
        std::cout << "\nCapacity : " << g1.capacity();
        std::cout << "\nMax_Size : " << g1.max_size();
    */
    /*
        // resizes the vector size to 4
        g1.resize(4);

        // prints the vector size after resize()
        cout << "\nSize : " << g1.size();

        // checks if the vector is empty or not
        if (g1.empty() == false)
            cout << "\nVector is not empty";
        else
            cout << "\nVector is empty";

        cout << "\nVector elements are: ";
        for (auto it = g1.begin(); it != g1.end(); it++)
            cout << *it << " ";
        cout << endl;
    */
    return;
}

void erase_vector()
{
    std::vector<int> stdvector;

    std::cout << "stdvector size:" << stdvector.size() << std::endl;
    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
        stdvector.push_back(i);

    // display begin element
    std::cout << *stdvector.begin() << std::endl;

    std::cout << "address of 6th elem: " << &stdvector[5] << std::endl;
    std::cout << "value  of 6th elem: " << stdvector[5] << std::endl;
    // erase the 6th element
    // stdvector.erase(stdvector.begin() + 5);

    std::cout << "value after function: " << *stdvector.erase(stdvector.begin() + 5) << std::endl;
    std::cout << "address of 6th elem: " << &stdvector[5] << std::endl;
    std::cout << "value  of 6th elem: " << stdvector[5] << std::endl;

    // erase the first 3 elements:
    stdvector.erase(stdvector.begin(), stdvector.begin() + 3);
    std::cout << "stdvector size:" << stdvector.size() << std::endl;
    std::cout << "stdvector contains:";
    for (int i = 0; i < stdvector.size(); ++i)
        std::cout << ' ' << stdvector[i];
    std::cout << '\n';
};

void erase_ft_vector()
{
    ft::vector<int> ft_vector;
    std::cout << "ft_vector size:" << ft_vector.size() << std::endl;
    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
        ft_vector.push_back(i);

    // display begin element
    std::cout << *ft_vector.begin() << std::endl;
    // erase the 6th element

    std::cout << "address of 6th elem: " << &ft_vector[5] << std::endl;
    std::cout << "value  of 6th elem: " << ft_vector[5] << std::endl;
    ft_vector.erase(ft_vector.begin() + 5);

    std::cout << "address of 6th elem: " << &ft_vector[5] << std::endl;
    std::cout << "value  of 6th elem: " << ft_vector[5] << std::endl;

    // erase the first 3 elements:
    ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 3);
    std::cout << "ft_vector size:" << ft_vector.size() << std::endl;
    std::cout << "ft_vector contains:";
    for (int i = 0; i < ft_vector.size(); ++i)
        std::cout << ' ' << ft_vector[i];
    std::cout << '\n';
};

void insert_vector()
{
    std::vector<int>           myvector(3, 100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
};

void insert_ft_vector()
{

    ft::vector<int>           myvector(3, 100);
    ft::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    ft::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
};
int main()
{
    /*
    test_utility_equal();
    test_utility_ftequal();
    test_utility_lexico();
    test_utility_ftlexico();
    */
    // std_vec();
    // ft_vec();
    // std::map;
    // std::stack;
    // std::vector;
    erase_vector();
    erase_ft_vector();
    std::cout << "-----" << std::endl;
    insert_vector();
    insert_ft_vector();
    return (0);
}
