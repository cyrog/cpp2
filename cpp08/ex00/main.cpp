#include "easyfind.hpp"

int	main(void) {
	
	std::vector<int> test;
	//std::list<int> test;
	
	test.push_back(12);
	test.push_back(42);
	test.push_back(666);
	test.push_back(1024);
	test.push_back(2048);
	easyfind(test, 12);
	//easyfind(test, 22);
	
	try {
		easyfind(test, 46);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
}
