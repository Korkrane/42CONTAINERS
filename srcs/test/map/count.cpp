#include "../test.hpp"

template <typename T>
void count()
{
    T mymap;
    char c;

 mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else
      std::cout << " is not an element of mymap.\n";
  }
}

int main()
{
  count<NAMESPACE::map<char, int> >();
}