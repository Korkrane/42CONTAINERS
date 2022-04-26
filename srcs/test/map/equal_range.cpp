#include "../test.hpp"

template <typename T>
void equal_range()
{
		T mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		NAMESPACE::pair<typename T::iterator,typename T::iterator> ret;
		ret = mymap.equal_range('b');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
}


int main()
{
	equal_range<NAMESPACE::map<char, int> >();
}
