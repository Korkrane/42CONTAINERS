#include "../test.hpp"

template <typename T>
void empty(std::ofstream &output)
{
    T myvector;

    int sum(0);

    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    output << "total: " << sum << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.empty");
    empty<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.empty");
    empty<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.empty ./results/vector/ft.empty");
    if (result == 0)
        std::cout << "empty \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "empty \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}