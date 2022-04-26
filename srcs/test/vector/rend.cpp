#include "../test.hpp"

template <typename T>
void rend()
{
    T myvector(5);

    typename T::reverse_iterator rit = myvector.rbegin();

    int i                            = 0;
    for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (typename T::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main()
{
    rend<NAMESPACE::vector<int> >();

}