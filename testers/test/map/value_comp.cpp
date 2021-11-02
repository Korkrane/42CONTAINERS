#include "../test.hpp"

template <typename T>
void value_comp(std::ofstream &output)
{
    T mymap;

mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  output << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.rbegin();          // last element

  typename T::iterator it = mymap.begin();
  do {
    output << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

}

int main()
{
    std::ofstream std_out("./results/map/std.value_comp");
    value_comp<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.value_comp");
    //value_comp<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.value_comp ./results/map/ft.value_comp");
    if (result == 0)
        std::cout << "value_comp \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "value_comp \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}