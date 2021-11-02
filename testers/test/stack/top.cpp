#include "../test.hpp"

template <typename T>
void top(std::ofstream &output)
{
    T mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    output << "mystack.top() is now " << mystack.top() << '\n';
}

int main()
{
    std::ofstream std_out("./results/stack/std.top");
    top<std::stack<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/stack/ft.top");
    top<ft::stack<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/stack/std.top ./results/stack/ft.top");
    if (result == 0)
        std::cout << "top \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "top \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}