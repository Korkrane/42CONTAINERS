#include "../test.hpp"

template <typename T>
void reserve(std::ofstream &output)
{
    typename T::size_type sz;

    T foo;
    sz = foo.capacity();
    output << "making foo grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        foo.push_back(i);
        if (sz != foo.capacity())
        {
            sz = foo.capacity();
            output << "capacity changed: " << sz << '\n';
        }
    }

    T bar;
    sz = bar.capacity();
    bar.reserve(100); // this is the only difference with foo above
    output << "making bar grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        bar.push_back(i);
        if (sz != bar.capacity())
        {
            sz = bar.capacity();
            output << "capacity changed: " << sz << '\n';
        }
    }
}

int main()
{
    std::ofstream std_out("./results/vector/std.reserve");
    reserve<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.reserve");
    reserve<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.reserve ./results/vector/ft.reserve");
    if (result == 0)
        std::cout << "reserve \t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "reserve \t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}