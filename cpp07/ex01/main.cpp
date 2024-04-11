#include "iter.hpp"

int	main(void) {

	std::cout << "_____ printing some ints _____" << std::endl;

	int arrInt[] = { 9, 12, -42, 66, -12 };
	size_t arrSize = sizeof(arrInt) / sizeof(arrInt[0]);
	iter(arrInt, arrSize, print);

	std::cout << "_____ printing some strings _____" << std::endl;

	std::string bsxString[]  = { "bsx", "les", "michtos" };
	size_t bsxSize = sizeof(bsxString) / sizeof(bsxString[0]);
	iter(bsxString, bsxSize, print);

	std::cout << "_____ printing some floats _____" << std::endl;
	float arrFloat[] = { 9.12, 42.42, 66.66, -42.42 };
	size_t arrFSize = sizeof(arrFloat) / sizeof(arrFloat[0]);
	iter(arrFloat, arrFSize, print);

}
