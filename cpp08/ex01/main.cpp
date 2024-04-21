#include "Span.hpp"

int	main(void) {

	int	size = 4;
	Span	test(size);
	
	try {
		test.addNumber(2);
		test.addNumber(7);
		test.addNumber(42);
		test.addNumber(66);
//		test.addNumber(66);
	}
	catch (std::overflow_error &e) {
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < size; i++) {
		std::cout << test.getNumber(i) << std::endl;
	}

	test.shortestSpan();
	std::cout << "_______________" << std::endl;
	test.longestSpan();

	std::cout << " ___ big numbers ___ " << std::endl;
	
	int	newSize = 99;
	Span big(newSize);
	try {
		std::vector<int> bigtest;
		bigtest.push_back(13);
		bigtest.push_back(12);
		bigtest.push_back(18);
		bigtest.push_back(19);
		big.addRange(bigtest.begin(),  bigtest.end());
	}
	catch (Span::tooShort &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::overflow_error &e) {
		std::cerr << e.what() << std::endl;
	}

	big.shortestSpan();
	big.longestSpan();
}
