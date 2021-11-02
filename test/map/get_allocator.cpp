#include "../test.hpp"

template <typename T>
void get_allocator(std::ofstream &output)
{
    int psize;
    T mymap;
    std::pair<const char, int> *p;

 // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(std::map<char,int>::value_type)*5;

    output << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);

}

int main()
{
    std::ofstream std_out("./results/map/std.get_allocator");
    get_allocator<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.get_allocator");
    //get_allocator<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.get_allocator ./results/map/ft.get_allocator");
    if (result == 0)
        std::cout << "get_allocator \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "get_allocator \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}