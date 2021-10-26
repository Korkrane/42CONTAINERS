#include "../test.hpp"

template <typename T>
void size(std::ofstream &output)
{
    T myints;

    output << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 10; i++)
        myints.push_back(i);
    output << "1. size: " << myints.size() << '\n';

    myints.insert(myints.end(), 10, 100);
    output << "2. size: " << myints.size() << '\n';

    myints.pop_back();
    output << "3. size: " << myints.size() << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.size");
    size<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.size");
    size<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.size ./results/vector/ft.size");
    if (result == 0)
        std::cout << "size \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "size \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}