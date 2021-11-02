#include "../test.hpp"

template <typename T>
void size(std::ofstream &output)
{
    T myints;

    output << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 5; i++)
        myints.push(i);
    output << "1. size: " << myints.size() << '\n';

    myints.pop();
    output << "2. size: " << myints.size() << '\n';
}

int main()
{
    std::ofstream std_out("./results/stack/std.size");
    size<std::stack<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/stack/ft.size");
    size<ft::stack<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/stack/std.size ./results/stack/ft.size");
    if (result == 0)
        std::cout << "size \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "size \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}