#include "../test.hpp"

template <typename T>
void front(std::ofstream &output)
{
    T myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();

    output << "myvector.front() is now " << myvector.front() << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.front");
    front<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.front");
    front<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.front ./results/vector/ft.front");
    if (result == 0)
        std::cout << "front \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "front \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}