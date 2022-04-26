#include "../test.hpp"

template <typename T>
void duplicate_key()
{
    T mymap;

    mymap['x'] = 1001;
    mymap['x'] = 2002;
    mymap['z'] = 3003;
    mymap['y'] = 2002;

    std::cout << "mymap contains:\n";

    NAMESPACE::pair<char, int> highest = *mymap.rbegin(); // last element

    typename T::iterator it = mymap.begin();
    do
    {
        std::cout << it->first << " => " << it->second << '\n';
    } while (mymap.value_comp()(*it++, highest));
}

int main()
{
   duplicate_key<NAMESPACE::map<char, int> >();
}