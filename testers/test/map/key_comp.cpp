#include "../test.hpp"

template <typename T>
void key_comp(std::ofstream &output)
{
    T mymap;
    typename T::key_compare mycomp = mymap.key_comp();

mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  output << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    output << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  output << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.key_comp");
    key_comp<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.key_comp");
    //key_comp<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.key_comp ./results/map/ft.key_comp");
    if (result == 0)
        std::cout << "key_comp \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "key_comp \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}