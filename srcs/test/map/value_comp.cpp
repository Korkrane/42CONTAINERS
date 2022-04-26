#include "../test.hpp"

template <typename T>
void value_comp()
{
    T mymap;

mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element

  typename T::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

}

int main()
{
  value_comp<NAMESPACE::map<char, int> >();

}