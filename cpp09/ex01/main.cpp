#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "error: usage: ./RPN <RPN expression>" << std::endl;
		return -1;
	}

	RPN	rpn;

	try {
		int result = rpn.evaluateRPN(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}



