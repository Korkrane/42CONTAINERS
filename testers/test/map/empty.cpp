#include "../test.hpp"

template <typename T>
void empty(std::ofstream &output)
{
    T mymap;

 mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    output << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
}

int main()
{
    std::ofstream std_out("./results/map/std.empty");
    empty<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.empty");
    //empty<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.empty ./results/map/ft.empty");
    if (result == 0)
        std::cout << "empty \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "empty \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}