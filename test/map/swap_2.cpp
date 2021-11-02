#include "../test.hpp"

template <typename T>
void swap_2(std::ofstream &output)
{
    T foo, bar;
 foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  swap(foo,bar);

  output << "foo contains:\n";
  for (typename T::iterator it=foo.begin(); it!=foo.end(); ++it)
    output << it->first << " => " << it->second << '\n';

  output << "bar contains:\n";
  for (typename T::iterator it=bar.begin(); it!=bar.end(); ++it)
    output << it->first << " => " << it->second << '\n';

}

int main()
{
    std::ofstream std_out("./results/map/std.swap_2");
    swap_2<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.swap_2");
    //swap_2<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.swap_2 ./results/map/ft.swap_2");
    if (result == 0)
        std::cout << "swap_2 \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "swap_2 \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}