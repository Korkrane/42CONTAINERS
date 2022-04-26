#include "../test.hpp"

template <typename T>
void begin()
{
    T mymap;

    mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  for (typename T::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

int main()
{
    begin<NAMESPACE::map<char, int> >();
}
