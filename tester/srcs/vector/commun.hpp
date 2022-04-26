#ifndef COMMUN_HPP
# define COMMUN_HPP

#include "../srcs/vector.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#ifndef NAMESPACE
    # define NAMESPACE ft
#endif

template <typename T>
void    print_vector(NAMESPACE::vector<T> const &vector_test, bool capacity = false)
{
    for(size_t i = 0; i < vector_test.size(); i++)
	{
		std::cout << vector_test[i] << std::endl;
	}
    if(capacity)
    {
            std::cout << "--INFOS--" << std::endl;
	        std::cout << "Size = " <<  vector_test.size();
            if(vector_test.empty())
            {
                std::cout << " [empty]";
            }
            //std::cout << std::endl << "Capacity = " << vector_test.capacity() << std::endl;
            std::cout << "Max_size = "<< vector_test.max_size() << std::endl;
    }
}

class foo {
	public:
		foo(void) { };
		~foo(void) { };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(int src) { this->value = src; return *this; };
		int getValue(void) const { return this->value; };
	private:
		int	value;
};

std::ostream	&operator<<(std::ostream &o, foo const &bar) {
	o << bar.getValue();
	return o;
}

#endif