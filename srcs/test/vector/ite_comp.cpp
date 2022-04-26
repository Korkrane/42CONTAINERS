#include "../test.hpp"

template <typename T>
void ite_comp()
{
    T foo(3, 100); // three ints with a value of 100
    T bar(5, 200); // five ints with a value of 200

    typename T::iterator it_bar = bar.begin();
    const typename T::iterator it_foo = foo.begin();

    //comp it & const it
    if (it_foo == it_bar)
        std::cout << "it_foo and it_bar are equal\n";
    if (it_foo != it_bar)
        std::cout << "it_foo and it_bar are not equal\n";
    if (it_foo < it_bar)
        std::cout << "it_foo is less than it_bar\n";
    if (it_foo > it_bar)
        std::cout << "it_foo is greater than it_bar\n";
    if (it_foo <= it_bar)
        std::cout << "it_foo is less than or equal to it_bar\n";
    if (it_foo >= it_bar)
        std::cout << "it_foo is greater than or equal to it_bar\n";
}

int main()
{
    ite_comp<NAMESPACE::vector<int> >();
}