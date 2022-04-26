#include "../test.hpp"

template <typename T>
void size()
{
    T mymap;

mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
}

int main()
{
    size<NAMESPACE::map<char, int> >();

}