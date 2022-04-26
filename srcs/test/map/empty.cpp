#include "../test.hpp"

template <typename T>
void empty()
{
    T mymap;

 mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
}

int main()
{
  empty<NAMESPACE::map<char, int> >();
}