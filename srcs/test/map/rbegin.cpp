#include "../test.hpp"

template <typename T>
void rbegin()
{
    T mymap;

mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  typename T::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
}

int main()
{
    rbegin<NAMESPACE::map<char, int> >();

}