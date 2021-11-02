#include "../test.hpp"

template <typename T>
void equal_range(std::ofstream &output)
{
    T mymap;

mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<typename T::iterator,typename T::iterator> ret;
  ret = mymap.equal_range('b');

  output << "lower bound points to: ";
  output << ret.first->first << " => " << ret.first->second << '\n';

  output << "upper bound points to: ";
  output << ret.second->first << " => " << ret.second->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.equal_range");
    equal_range<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.equal_range");
    //equal_range<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.equal_range ./results/map/ft.equal_range");
    if (result == 0)
        std::cout << "equal_range \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "equal_range \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}