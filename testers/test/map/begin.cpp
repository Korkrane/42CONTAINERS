#include "../test.hpp"

template <typename T>
void begin(std::ofstream &output)
{
    T mymap;
    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    for (typename T::iterator it = mymap.begin(); it != mymap.end(); ++it)
        output << it->first << " => " << it->second << '\n';
}

int main()
{
    std::ofstream std_out("./results/map/std.begin");
    begin<std::map<char, int>>(std_out);
    std_out.close();

    std::ofstream ft_out("./results/map/ft.begin");
    // begin<ft::map<char, int>>(ft_out);
    ft_out.close();

    int result = system("diff ./results/map/std.begin ./results/map/ft.begin");
    if (result == 0)
        std::cout << "begin \t\t\t\t\e[0;32m[OK]\e[0m" << std::endl;
    else
        std::cout << "begin \t\t\t\t\e[0;31m[KO]\e[0m" << std::endl;
}