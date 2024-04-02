#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "usage is 1 arg only" << std::endl;
		return 0;
	}

	ScalarConverter::convert(argv[1]);
}
