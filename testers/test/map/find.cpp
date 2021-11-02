#include "../test.hpp"

template <typename T>
void find(std::ofstream &output)
{
    T mymap;
    typename T::iterator it;

mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  output << "elements in mymap:" << '\n';
  output << "a => " << mymap.find('a')->second << '\n';
  output << "c => " << mymap.find('c')->second << '\n';
  output << "d => " << mymap.find('d')->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.find");
    find<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.find");
    //find<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.find ./results/map/ft.find");
    if (result == 0)
        std::cout << "find \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "find \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}