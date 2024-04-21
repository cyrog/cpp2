#include "easyfind.hpp"

int	main(void) {

	std::cout << std::endl << " ____ first test ____ " << std::endl << std::endl; 

	std::vector<int> test;
	test.push_back(12);
	test.push_back(13);
	test.push_back(92);
	test.push_back(66);
	test.push_back(42);
	easyfind(test, 66);

	std::cout << std::endl << " ____ smth else ____ " << std::endl;

	try {
		easyfind(test, 43);
	}
	catch (const std::exception &e) {
		std::cerr << std::endl << e.what() << std::endl;
	}
}
