#include "../test.hpp"

template <typename T>
void pop_back(std::ofstream &output)
{
    T   myvector;
    int sum(0);
    myvector.push_back(100);
    myvector.push_back(200);
    myvector.push_back(300);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    output << "The elements of myvector add up to " << sum << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.pop_back");
    pop_back<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.pop_back");
    pop_back<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.pop_back ./results/vector/ft.pop_back");
    if (result == 0)
        std::cout << "pop_back \t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "pop_back \t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}