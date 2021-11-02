#include "../test.hpp"

template <typename T>
void rend(std::ofstream &output)
{
    T myvector(5);

    typename T::reverse_iterator rit = myvector.rbegin();

    int i                            = 0;
    for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
        *rit = ++i;

    output << "myvector contains:";
    for (typename T::iterator it = myvector.begin(); it != myvector.end(); ++it)
        output << ' ' << *it;
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.rend");
    rend<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.rend");
    rend<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.rend ./results/vector/ft.rend");
    if (result == 0)
        std::cout << "rend \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "rend \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}