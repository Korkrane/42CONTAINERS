#include "../test.hpp"

template <typename T>
void pop_back()
{
    T   myvector;
    int sum(0);
    myvector.push_back(100);
    myvector.push_back(200);
    myvector.push_back(300);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    std::cout << "The elements of myvector add up to " << sum << '\n';
}

int main()
{
    pop_back<NAMESPACE::vector<int> >();

}