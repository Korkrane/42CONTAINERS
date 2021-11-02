#include "../test.hpp"

template <typename T>
void clear(std::ofstream &output)
{
    T mymap;

 mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

output << "mymap contains:\n";
  for (typename T::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    output << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;

  output << "mymap contains:\n";
  for (typename T::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    output << it->first << " => " << it->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.clear");
    clear<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.clear");
    //clear<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.clear ./results/map/ft.clear");
    if (result == 0)
        std::cout << "clear \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "clear \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}