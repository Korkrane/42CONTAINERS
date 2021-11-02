#include "../test.hpp"

template <typename T>
void rbegin(std::ofstream &output)
{
    T mymap;

mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  typename T::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    output << rit->first << " => " << rit->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.rbegin");
    rbegin<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.rbegin");
    //rbegin<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.rbegin ./results/map/ft.rbegin");
    if (result == 0)
        std::cout << "rbegin \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "rbegin \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}