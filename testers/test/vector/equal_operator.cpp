#include "../test.hpp"

template <typename T>
void equal_operator(std::ofstream &output)
{
    T foo(3, 0);
    T bar(5, 0);

    bar = foo;
    foo = T();

    output << "Size of foo: " << int(foo.size()) << '\n';
    output << "Size of bar: " << int(bar.size()) << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.equal_operator");
    equal_operator<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.equal_operator");
    equal_operator<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.equal_operator ./results/vector/ft.equal_operator");
    if (result == 0)
        std::cout << "equal_operator \t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "equal_operator \t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}