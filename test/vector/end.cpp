#include "../test.hpp"

template <typename T>
void end(std::ofstream &output)
{
    T myvector;
    for (int i = 1; i <= 5; i++)
        myvector.push_back(i);

    output << "myvector contains:";
    for (typename T::iterator it = myvector.begin(); it != myvector.end(); ++it)
        output << ' ' << *it;
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.end");
    end<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.end");
    end<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.end ./results/vector/ft.end");
    if (result == 0)
        std::cout << "end \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "end \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}