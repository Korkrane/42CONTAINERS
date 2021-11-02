#include "../test.hpp"

template <typename T>
void rend(std::ofstream &output)
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
    std::ofstream std_out("./results/map/std.rend");
    rend<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.rend");
    //rend<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.rend ./results/map/ft.rend");
    if (result == 0)
        std::cout << "rend \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "rend \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}