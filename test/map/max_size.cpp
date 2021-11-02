#include "../test.hpp"

template <typename T>
void max_size(std::ofstream &output)
{
    T mymap;
    int i;

 if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    output << "The map contains 1000 elements.\n";
  }
  else output << "The map could not hold 1000 elements.\n";
}

int main()
{
    std::ofstream std_out("./results/map/std.max_size");
    max_size<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.max_size");
    //max_size<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.max_size ./results/map/ft.max_size");
    if (result == 0)
        std::cout << "max_size \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "max_size \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}