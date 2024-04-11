#include "Array.hpp"

int	main(void) {

	std::cout << " ___ empty int array ___ " << std::endl;

	try {
		Array<int> intEmpty;
		std::cout << "arr size: " << intEmpty.size() << std::endl;
	}
	catch (const Array<int>::IndexOutOfBounds &e) {
		std::cerr << "exception: " << e.what() << std::endl;
	}

	std::cout << " ___ 3 int array ___ " << std::endl;

	try {
		Array<int> int3(2);
		std::cout << "arr size: " << int3.size() << std::endl;
		int3[0] = 1;
		int3[1] = 2;
		//int3[2] = 3; //test outofbounds
		for (unsigned int i = 0; i < int3.size(); i++) {
			std::cout << int3[i] << std::endl;
		}
	}
	catch (const Array<int>::IndexOutOfBounds &e) {
		std::cerr << "exception: " << e.what() << std::endl;
	}

	try {
		std::cout << " ___ test operator= ___ " << std::endl;
		Array<std::string>	test(3);
		test[0] = "test";
		test[1] = "test2";
		test[2] = "test3";
		//test[3] = "test4"; //out of bounds
		std::cout << "arr size: " << test.size() << std::endl;
		for (unsigned int i = 0; i < test.size(); i++) {
			std::cout << test[i] << std::endl;
		}
	}
	catch (const Array<std::string>::IndexOutOfBounds &e) {
		std::cerr << "exception: " << e.what() << std::endl;
	}
}
