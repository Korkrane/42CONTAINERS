#include "../test.hpp"

template <typename T>
void swap_2()
{
    T foo(3, 100); // three ints with a value of 100
    T bar(5, 200); // five ints with a value of 200

    typename T::iterator it_bar = bar.begin();
    typename T::iterator it_foo = foo.begin();
    foo.swap(bar);

    std::cout << "foo contains:";
    for (typename T::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "bar contains:";
    for (typename T::iterator it = bar.begin(); it != bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "it_foo value: " << *it_foo << " should remain 100" << std::endl;
    std::cout << "it_bar value: " << *it_bar << " should remain 200" << std::endl;
}

int main()
{
    swap_2<NAMESPACE::vector<int> >();
}