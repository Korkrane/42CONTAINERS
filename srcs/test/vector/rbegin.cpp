#include "../test.hpp"

template <typename T>
void rbegin()
{
    T   myvector(5);
    int i                            = 0;

    typename T::reverse_iterator rit = myvector.rbegin();
    for (; rit != myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (typename T::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main()
{
    rbegin<NAMESPACE::vector<int> >();

}