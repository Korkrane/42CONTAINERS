#include "../test.hpp"

template <typename T>
void bracket_operator(std::ofstream &output)
{
    T mymap;

 mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  output << "mymap['a'] is " << mymap['a'] << '\n';
  output << "mymap['b'] is " << mymap['b'] << '\n';
  output << "mymap['c'] is " << mymap['c'] << '\n';
  output << "mymap['d'] is " << mymap['d'] << '\n';

  output << "mymap now contains " << mymap.size() << " elements.\n";

}

int main()
{
    std::ofstream std_out("./results/map/std.bracket_operator");
    bracket_operator<std::map<char, std::string>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.bracket_operator");
    //bracket_operator<ft::map<char, std::string>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.bracket_operator ./results/map/ft.bracket_operator");
    if (result == 0)
        std::cout << "bracket_operator \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "bracket_operator \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}