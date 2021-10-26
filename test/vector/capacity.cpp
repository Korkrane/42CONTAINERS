#include "../test.hpp"

template <typename T>
void capacity(std::ofstream &output)
{
    T myvector;

    // set some content in the vector:
    for (int i = 0; i < 100; i++)
        myvector.push_back(i);

    output << "size: " << (int)myvector.size() << '\n';
    output << "capacity: " << (int)myvector.capacity() << '\n';
    output << "max_size: " << (int)myvector.max_size() << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.capacity");
    capacity<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.capacity");
    capacity<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.capacity ./results/vector/ft.capacity");
    if (result == 0)
        std::cout << "capacity \t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "capacity \t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}