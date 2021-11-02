#include "../test.hpp"

template <typename T>
void erase(std::ofstream &output)
{
    T myvector;

    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);

    // erase the 6th element
    myvector.erase(myvector.begin() + 5);

    // erase the first 3 elements:
    myvector.erase(myvector.begin(), myvector.begin() + 3);

    output << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); ++i)
        output << ' ' << myvector[i];
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.erase");
    erase<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.erase");
    erase<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.erase ./results/vector/ft.erase");
    if (result == 0)
        std::cout << "erase \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "erase \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}