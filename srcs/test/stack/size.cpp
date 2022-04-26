#include "../test.hpp"

template <typename T>
void size()
{
    T myints;

    std::cout << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 5; i++)
        myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
}

int main()
{
    size<NAMESPACE::stack<int> >();

}