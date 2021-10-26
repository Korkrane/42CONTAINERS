#include "../test.hpp"

template <typename T>
void empty(std::ofstream &output)
{
    T   mystack;
    int sum(0);

    for (int i = 1; i <= 10; i++)
        mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    output << "total: " << sum << '\n';
}

int main()
{
    std::ofstream std_out("./results/stack/std.empty");
    empty<std::stack<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/stack/ft.empty");
    empty<ft::stack<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/stack/std.empty ./results/stack/ft.empty");
    if (result == 0)
        std::cout << "empty \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "empty \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}