#include "../test.hpp"

template <typename T>
void lower_bound(std::ofstream &output)
{
    T mymap;
    typename T::iterator itlow, itup;

 mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (typename T::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    output << it->first << " => " << it->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.lower_bound");
    lower_bound<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.lower_bound");
    //lower_bound<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.lower_bound ./results/map/ft.lower_bound");
    if (result == 0)
        std::cout << "lower_bound \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "lower_bound \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}