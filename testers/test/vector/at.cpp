#include "../test.hpp"

template <typename T>
void at(std::ofstream &output)
{
    T myvector(10);
    // assign some values:
    for (unsigned i = 0; i < myvector.size(); i++)
        myvector.at(i) = i;

    output << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        output << ' ' << myvector.at(i);
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.at");
    at<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.at");
    at<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.at ./results/vector/ft.at");
    if (result == 0)
        std::cout << "at \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "at \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}