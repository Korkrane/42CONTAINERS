#include "../test.hpp"

template <typename T>
void pushback(std::ofstream &output)
{
    T myvector;

    for (int i = 0; i < 5; i++)
        myvector.push_back(i);
    for (typename T::iterator it = myvector.begin(); it != myvector.end(); ++it)
        output << ' ' << *it;
    output << ' ';
    output << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

int main()
{
    std::ofstream std_out("./results/vector/std.push_back");
    pushback<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.push_back");
    pushback<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.push_back ./results/vector/ft.push_back");
    if (result == 0)
        std::cout << "push_back \t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "push_back \t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}
