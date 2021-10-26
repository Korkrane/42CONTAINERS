#include "../test.hpp"

template <typename T>
void resize(std::ofstream &output)
{
    T myvector;
    // set some initial content:
    for (int i = 1; i < 10; i++)
        myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8, 100);
    myvector.resize(12);

    output << "myvector contains:";
    for (unsigned long i = 0; i < myvector.size(); i++)
        output << ' ' << myvector[i];
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.resize");
    resize<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.resize");
    resize<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.resize ./results/vector/ft.resize");
    if (result == 0)
        std::cout << "resize \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "resize \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}