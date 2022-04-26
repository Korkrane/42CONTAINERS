#include "../test.hpp"

template <typename T>
void relational_operator()
{
    T foo;
    T bar;

    for (int i = 0; i < 10; i++)
    {
        bar.push(i);
        foo.push(1);
    }

    if (foo == bar)
        std::cout << "foo and bar are equal\n";
    if (foo != bar)
        std::cout << "foo and bar are not equal\n";
    if (foo < bar)
        std::cout << "foo is less than bar\n";
    if (foo > bar)
        std::cout << "foo is greater than bar\n";
    if (foo <= bar)
        std::cout << "foo is less than or equal to bar\n";
    if (foo >= bar)
        std::cout << "foo is greater than or equal to bar\n";
}

int main()
{
    relational_operator<NAMESPACE::stack<int> >();

}