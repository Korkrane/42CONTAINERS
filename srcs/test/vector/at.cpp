#include "../test.hpp"

template <typename T>
void at()
{
    T myvector(10);
    // assign some values:
    for (unsigned i = 0; i < myvector.size(); i++)
        myvector.at(i) = i;

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';
}

int main()
{
    at<NAMESPACE::vector<int> >();

}