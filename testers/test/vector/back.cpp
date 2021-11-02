#include "../test.hpp"

template <typename T>
void back(std::ofstream &output)
{
    T myvector;

    myvector.push_back(10);

    while (myvector.back() != 0)
    {
        myvector.push_back(myvector.back() - 1);
    }

    output << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        output << ' ' << myvector[i];
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.back");
    back<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.back");
    back<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.back ./results/vector/ft.back");
    if (result == 0)
        std::cout << "back \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "back \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}