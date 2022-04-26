#include "../test.hpp"

template <typename T>
void max_size()
{
    T myvector;

    // set some content in the vector:
    for (int i = 0; i < 100; i++)
        myvector.push_back(i);

    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";
}

int main()
{
    max_size<NAMESPACE::vector<int> >();

}