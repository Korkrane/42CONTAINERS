#include "../test.hpp"

template <typename T>
void insert(std::ofstream &output)
{
    T                    myvector;
    typename T::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    T anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    output << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        output << ' ' << *it;
    output << '\n';
}

int main()
{
    std::ofstream std_out("./results/vector/std.insert");
    insert<std::vector<int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/vector/ft.insert");
    insert<ft::vector<int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/vector/std.insert ./results/vector/ft.insert");
    if (result == 0)
        std::cout << "insert \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "insert \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}