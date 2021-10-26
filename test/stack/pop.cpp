#include "../test.hpp"

template <typename T>
void pop(std::ofstream &output)
{
    T mystack;

    for (int i = 0; i < 5; ++i)
        mystack.push(i);

    output << "Popping out elements...";
    while (!mystack.empty())
    {
        output << ' ' << mystack.top();
        mystack.pop();
    }
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/stack/std.pop");
    pop<std::stack<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/stack/ft.pop");
    pop<ft::stack<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/stack/std.pop ./results/stack/ft.pop");
    if (result == 0)
        std::cout << "pop \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "pop \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}