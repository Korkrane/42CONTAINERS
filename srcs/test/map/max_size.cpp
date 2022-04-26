#include "../test.hpp"

template <typename T>
void max_size()
{
    T mymap;
    int i;

 if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";
}

int main()
{
  max_size<NAMESPACE::map<char, int> >();

}