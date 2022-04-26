#include "../test.hpp"

template <typename T>
void push()
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
    push<NAMESPACE::stack<int> >();

}