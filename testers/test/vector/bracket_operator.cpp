#include "../test.hpp"

template <typename T>
void bracket_operator(std::ofstream &output)
{
T myvector (10);   // 10 zero-initialized elements

 typename T::size_type sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  output << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    output << ' ' << myvector[i];
  output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.bracket_operator");
    bracket_operator<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.bracket_operator");
    bracket_operator<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.bracket_operator ./results/vector/ft.bracket_operator");
    if ( result == 0)
    std::cout << "bracket_operator \t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
    std::cout << "bracket_operator \t\t\e[0;31m[KO]\e[0m" << std::endl;

}