#include "../test.hpp"

template <typename T>
void erase(std::ofstream &output)
{
    T mymap;
    typename T::iterator it;

// insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    output << it->first << " => " << it->second << '\n';

}

int main()
{
    std::ofstream std_out("./results/map/std.erase");
    erase<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.erase");
    //erase<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.erase ./results/map/ft.erase");
    if (result == 0)
        std::cout << "erase \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "erase \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}