#include "../test.hpp"

template <typename T>
void max_size(std::ofstream &output)
{
    T myvector;

    // set some content in the vector:
    for (int i = 0; i < 100; i++)
        myvector.push_back(i);

    output << "size: " << myvector.size() << "\n";
    output << "capacity: " << myvector.capacity() << "\n";
    output << "max_size: " << myvector.max_size() << "\n";
}

int main()
{
    std::ofstream std_out("./results/vector/std.max_size");
    max_size<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.max_size");
    max_size<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.max_size ./results/vector/ft.max_size");
    if (result == 0)
        std::cout << "max_size \t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "max_size \t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}