#include "../test.hpp"

template <typename T>
void relational_operators(std::ofstream &output)
{
    T foo, bar;

foo['a']=100;
  foo['b']=200;
  bar['a']=10;
  bar['z']=1000;

  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  if (foo==bar) output << "foo and bar are equal\n";
  if (foo!=bar) output << "foo and bar are not equal\n";
  if (foo< bar) output << "foo is less than bar\n";
  if (foo> bar) output << "foo is greater than bar\n";
  if (foo<=bar) output << "foo is less than or equal to bar\n";
  if (foo>=bar) output << "foo is greater than or equal to bar\n";

}

int main()
{
    std::ofstream std_out("./results/map/std.relational_operators");
    relational_operators<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.relational_operators");
    //relational_operators<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.relational_operators ./results/map/ft.relational_operators");
    if (result == 0)
        std::cout << "relational_operators \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "relational_operators \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}