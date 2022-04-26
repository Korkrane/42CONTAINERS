#include "../test.hpp"

template <typename T>
void end()
{
    T mymap;

mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (typename T::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

int main()
{
    end<NAMESPACE::map<char, int> >();
}