#include "../test.hpp"

template <typename T>
void reserve()
{
    typename T::size_type sz;

    T foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        foo.push_back(i);
        if (sz != foo.capacity())
        {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    T bar;
    sz = bar.capacity();
    bar.reserve(100); // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        bar.push_back(i);
        if (sz != bar.capacity())
        {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }
}

int main()
{
    reserve<NAMESPACE::vector<int> >();

}