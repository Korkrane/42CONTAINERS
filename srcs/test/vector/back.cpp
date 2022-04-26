#include "../test.hpp"

template <typename T>
void back()
{
    T myvector;

    myvector.push_back(10);

    while (myvector.back() != 0)
    {
        myvector.push_back(myvector.back() - 1);
    }

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
}

int main()
{
    back<NAMESPACE::vector<int> >();

}