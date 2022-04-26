#include "../test.hpp"

template <typename T>
void pop()
{
    T mystack;

    for (int i = 0; i < 5; ++i)
        mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
}

int main()
{
    pop<NAMESPACE::stack<int> >();

}