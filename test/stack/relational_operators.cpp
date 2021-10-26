#include "../test.hpp"

template <typename T>
void relational_operator(std::ofstream &output)
{
    T foo;
    T bar;

    for (int i = 0; i < 10; i++)
    {
        bar.push(i);
        foo.push(1);
    }

    if (foo == bar)
        output << "foo and bar are equal\n";
    if (foo != bar)
        output << "foo and bar are not equal\n";
    if (foo < bar)
        output << "foo is less than bar\n";
    if (foo > bar)
        output << "foo is greater than bar\n";
    if (foo <= bar)
        output << "foo is less than or equal to bar\n";
    if (foo >= bar)
        output << "foo is greater than or equal to bar\n";
}

int main()
{
    std::ofstream std_out("./results/stack/std.relational_operator");
    relational_operator<std::stack<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/stack/ft.relational_operator");
    relational_operator<ft::stack<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/stack/std.relational_operator ./results/stack/ft.relational_operator");
    if (result == 0)
        std::cout << "relational_operator \t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "relational_operator \t\t\e[0;31m[KO]\e[0m" << std::endl;
}