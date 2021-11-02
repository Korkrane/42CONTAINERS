#include "../test.hpp"

template <typename T>
void equal_operator(std::ofstream &output)
{
    T first, second;

 first['x']=8;
  first['y']=16;
  first['z']=32;

  second=first;                // second now contains 3 ints
  first=T();  // and first is now empty

  output << "Size of first: " << first.size() << '\n';
  output << "Size of second: " << second.size() << '\n';

}

int main()
{
    std::ofstream std_out("./results/map/std.equal_operator");
    equal_operator<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.equal_operator");
    //equal_operator<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.equal_operator ./results/map/ft.equal_operator");
    if (result == 0)
        std::cout << "equal_operator \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "equal_operator \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}