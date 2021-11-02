#include "../test.hpp"

template <typename T>
void ctor(std::ofstream &output)
{
    // constructors used in the same order as described above:
    T first;                               // empty vector of ints
    T second(4, 100);                      // four ints with value 100
    T third(second.begin(), second.end()); // iterating through second
    T fourth(third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    T   fifth(myints, myints + sizeof(myints) / sizeof(int));

    output << "The contents of fifth are:";
    for (typename T::iterator it = fifth.begin(); it != fifth.end(); ++it)
        output << ' ' << *it;
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.ctor");
    ctor<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.ctor");
    ctor<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.ctor ./results/vector/ft.ctor");
    if (result == 0)
        std::cout << "ctor \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "ctor \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}