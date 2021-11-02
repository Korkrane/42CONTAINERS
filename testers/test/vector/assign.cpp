#include "../test.hpp"

template <typename T>
void assign(std::ofstream &output)
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

    output << "Size of first: " << int(first.size()) << '\n';
    output << "Size of second: " << int(second.size()) << '\n';
    output << "Size of third: " << int(third.size()) << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.assign");
    assign<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.assign");
    assign<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.assign ./results/vector/ft.assign");
    if (result == 0)
        std::cout << "assign \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "assign \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}