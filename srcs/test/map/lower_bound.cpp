#include "../test.hpp"

template <typename T>
void lower_bound()
{
    T mymap;
    typename T::iterator itlow, itup;

 mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (typename T::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

int main()
{
    lower_bound<NAMESPACE::map<char, int> >();

}