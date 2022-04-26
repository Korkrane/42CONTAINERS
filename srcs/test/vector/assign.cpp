#include "../test.hpp"

template <typename T>
void assign()
{
    T first;
    T second;
    T third;
    first.assign(7, 100); // 7 ints with a value of 100
    typename T::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // the 5 central values of first

    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // assigning from array.

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    std::cout << "Size of third: " << int(third.size()) << '\n';
}

int main()
{
    assign<NAMESPACE::vector< int> >();
}