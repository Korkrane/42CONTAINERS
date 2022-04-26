#include "../test.hpp"

template <typename T>
void begin()
{
    T myvector;
    for (int i = 1; i <= 5; i++)
        myvector.push_back(i);

    std::cout << "myvector contains:";
    for (typename T::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main()
{
    begin<NAMESPACE::vector<int> >();

}