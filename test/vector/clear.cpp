#include "../test.hpp"

template <typename T>
void clear(std::ofstream &output)
{
    T myvector;

    myvector.push_back(100);
    myvector.push_back(200);
    myvector.push_back(300);

    output << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        output << ' ' << myvector[i];
    output << '\n';

    myvector.clear();
    myvector.push_back(1101);
    myvector.push_back(2202);

    output << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        output << ' ' << myvector[i];
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.clear");
    clear<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.clear");
    clear<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.clear ./results/vector/ft.clear");
    if (result == 0)
        std::cout << "clear \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "clear \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}