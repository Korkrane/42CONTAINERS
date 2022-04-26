#include "../test.hpp"

template <typename T>
void empty()
{
    T myvector;

    int sum(0);

    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    std::cout << "total: " << sum << '\n';
}

int main()
{
    empty<NAMESPACE::vector<int> >();

}