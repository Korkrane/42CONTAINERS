#include "../test.hpp"

template <typename T>
void get_allocator()
{
    int psize;
    T mymap;
    NAMESPACE::pair<const char, int> *p;

 // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(NAMESPACE::map<char,int>::value_type)*5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);

}

int main()
{
  get_allocator<NAMESPACE::map<char, int> >();

}