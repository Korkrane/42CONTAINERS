#include "../test.hpp"

template <typename T>
void equal_operator()
{
    T foo(3, 0);
    T bar(5, 0);

    bar = foo;
    foo = T();

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

int main()
{
    equal_operator<NAMESPACE::vector<int> >();

}