#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (ac != 2) {
		printErr("usage is 1 arg only");
		return 0;
	}

	ScalarConverter::convert(argv[1]);
}
