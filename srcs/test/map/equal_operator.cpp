#include "../test.hpp"

template <typename T>
void equal_operator()
{
    T first, second;

 first['x']=8;
  first['y']=16;
  first['z']=32;

  second=first;                // second now contains 3 ints
  first=T();  // and first is now empty

  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';

}

int main()
{
    equal_operator<NAMESPACE::map<char, int> >();
}