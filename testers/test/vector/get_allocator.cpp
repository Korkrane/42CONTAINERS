#include "../test.hpp"

template <typename T>
void get_allocator(std::ofstream &output)
{
    T            myvector;
    int         *p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i = 0; i < 5; i++)
        myvector.get_allocator().construct(&p[i], i);

    output << "The allocated array contains:";
    for (i = 0; i < 5; i++)
        output << ' ' << p[i];
    output << '\n';

    // destroy and deallocate:
    for (i = 0; i < 5; i++)
        myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p, 5);
}

int main()
{
    std::ofstream std_out("./results/vector/std.get_allocator");
    get_allocator<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.get_allocator");
    get_allocator<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.get_allocator ./results/vector/ft.get_allocator");
    if (result == 0)
        std::cout << "get_allocator \t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "get_allocator \t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}