#include "../test.hpp"

template <typename T>
void swap(std::ofstream &output)
{
    T foo, bar;

 foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  output << "foo contains:\n";
  for (typename T::iterator it=foo.begin(); it!=foo.end(); ++it)
    output << it->first << " => " << it->second << '\n';

  output << "bar contains:\n";
  for (typename T::iterator it=bar.begin(); it!=bar.end(); ++it)
    output << it->first << " => " << it->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.swap");
    swap<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.swap");
    //swap<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.swap ./results/map/ft.swap");
    if (result == 0)
        std::cout << "swap \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "swap \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}