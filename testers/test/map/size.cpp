#include "../test.hpp"

template <typename T>
void size(std::ofstream &output)
{
    T mymap;

mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  output << "mymap.size() is " << mymap.size() << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.size");
    size<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.size");
    //size<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.size ./results/map/ft.size");
    if (result == 0)
        std::cout << "size \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "size \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}