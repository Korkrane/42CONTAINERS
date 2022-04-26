#include "../test.hpp"

template <typename T>
void ctor()
{
    // constructors used in the same order as described above:
    T first;                               // empty vector of ints
    T second(4, 100);                      // four ints with value 100
    T third(second.begin(), second.end()); // iterating through second
    T fourth(third);                       // a copy of third
    T test = second;

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    T   fifth(myints, myints + sizeof(myints) / sizeof(int));

    std::cout << "The contents of fifth are:";
    for (typename T::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main()
{
        ctor<NAMESPACE::vector<int> >();
}