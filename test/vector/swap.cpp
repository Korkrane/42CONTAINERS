#include "../test.hpp"

template <typename T>
void swap(std::ofstream &output)
{
    T foo(3, 100); // three ints with a value of 100
    T bar(5, 200); // five ints with a value of 200

    foo.swap(bar);

    output << "foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
        output << ' ' << foo[i];
    output << '\n';

    output << "bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
        output << ' ' << bar[i];
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.swap");
    swap<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.swap");
    swap<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.swap ./results/vector/ft.swap");
    if (result == 0)
        std::cout << "swap \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "swap \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}