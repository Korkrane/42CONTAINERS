#include "../test.hpp"

template <typename T>
void insert(std::ofstream &output)
{
    T mymap;

// first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    output << "element 'z' already existed";
    output << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  output << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    output << it->first << " => " << it->second << '\n';

  output << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    output << it->first << " => " << it->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.insert");
    insert<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.insert");
    //insert<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.insert ./results/map/ft.insert");
    if (result == 0)
        std::cout << "insert \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "insert \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}