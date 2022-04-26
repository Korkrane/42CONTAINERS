#include "../test.hpp"

template <typename T>
void key_comp()
{
    T mymap;
    typename T::key_compare mycomp = mymap.key_comp();

mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  NAMESPACE::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
}

int main()
{
  key_comp<NAMESPACE::map<char, int> >();
}