#include "../test.hpp"

template <typename T>
void rbegin(std::ofstream &output)
{
    T   myvector(5);
    int i                            = 0;

    typename T::reverse_iterator rit = myvector.rbegin();
    for (; rit != myvector.rend(); ++rit)
        *rit = ++i;

    output << "myvector contains:";
    for (typename T::iterator it = myvector.begin(); it != myvector.end(); ++it)
        output << ' ' << *it;
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.rbegin");
    rbegin<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.rbegin");
    rbegin<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.rbegin ./results/vector/ft.rbegin");
    if (result == 0)
        std::cout << "rbegin \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "rbegin \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}