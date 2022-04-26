#include "../test.hpp"

template <typename T>
void top()
{
    T mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

int main()
{
    top<NAMESPACE::stack<int> >();

}