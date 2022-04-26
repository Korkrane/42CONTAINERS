#include "../test.hpp"

template <typename T>
void front()
{
    T myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();

    std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

int main()
{
    front<NAMESPACE::vector<int> >();

}