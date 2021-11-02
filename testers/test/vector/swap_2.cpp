#include "../test.hpp"

template <typename T>
void swap_2(std::ofstream &output)
{
    T foo(3, 100); // three ints with a value of 100
    T bar(5, 200); // five ints with a value of 200

    foo.swap(bar);

    output << "foo contains:";
    for (typename T::iterator it = foo.begin(); it != foo.end(); ++it)
        output << ' ' << *it;
    output << '\n';

    output << "bar contains:";
    for (typename T::iterator it = bar.begin(); it != bar.end(); ++it)
        output << ' ' << *it;
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.swap_2");
    swap_2<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.swap_2");
    swap_2<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.swap_2 ./results/vector/ft.swap_2");
    if (result == 0)
        std::cout << "swap_2 \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "swap_2 \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}