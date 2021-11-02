#include "../test.hpp"

template <typename T>
void count(std::ofstream &output)
{
    T mymap;
    char c;

 mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    output << c;
    if (mymap.count(c)>0)
      output << " is an element of mymap.\n";
    else
      output << " is not an element of mymap.\n";
  }
}

int main()
{
    std::ofstream std_out("./results/map/std.count");
    count<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.count");
    //count<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.count ./results/map/ft.count");
    if (result == 0)
        std::cout << "count \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "count \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}