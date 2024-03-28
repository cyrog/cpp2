#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void)src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs) {
	(void)rhs;
	return *this;
}

void	ScalarConverter::convChar(char nb) {
	if ((nb >= 0 && nb < 32) || nb == 127)
		std::cout << "char: non displayable character" << std::endl;
	if (nb < 0 || nb > 126)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << nb << std::endl;
}

void	ScalarConverter::convInt(int nb) {
	if (nb < INT_MAX && nb > INT_MIN)
		std::cout << "int: " << nb << std::endl;
	std::cout << "int: out of range" << std::endl;
}

void	ScalarConverter::convFloat(float nb) {
	std::cout << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
}

void	ScalarConverter::convDouble(double nb) {
	std::cout << std::fixed << std::setprecision(1) << nb << std::endl;
}

void	ScalarConverter::printChar(char nb) {
	convChar(nb);
	convInt(static_cast<int>(nb));
	convFloat(static_cast<float>(nb));
	convDouble(static_cast<double>(nb));
}

void	ScalarConverter::printInt(int nb) {
	convChar(static_cast<char>(nb));
	convInt(nb);
	convFloat(static_cast<float>(nb));
	convDouble(static_cast<double>(nb));
}

void	ScalarConverter::printFloat(float nb) {
	convChar(static_cast<char>(nb));
	convInt(static_cast<int>(nb));
	convFloat(nb);
	convDouble(static_cast<double>(nb));
}

void	ScalarConverter::printDouble(double nb) {
	convChar(static_cast<char>(nb));
	convInt(static_cast<int>(nb));
	convFloat(static_cast<float>(nb));
	convDouble(nb);
}

void	ScalarConverter::printSpe(std::string spe) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << spe << "f" << std::endl;
	std::cout << "double: " << spe << std::endl;
}

void	ScalarConverter::printErr(std::string msg) {
	std::cerr << "errpr: " << msg << std::endl;
}

void	ScalarConverter::getType(std::string str) {
	bool	isDouble = false;
	bool	isFloat = false;

	if (str.empty())
		return printErr("no input");
	if (std::isprint(str[0]) && str[0] != '-')
		return printChar(str[0]);
	for (int i = 0; i < (int)str.length(); i++) {
		if (i == 0 && str[0] == '-')
			i++;
		if (std::isdigit(str[i]))
			continue;
		if (str[i] == '.' && !isDouble)
			isDouble == true;
		if (str[i] == 'f' && isDouble == true && isFloat == false) {
			isDouble == false;
			isFloat == true;
		}
		else
			return printErr("conversion impossible");
	}
	if (isDouble) {
		double d = std::stod(str);
		printDouble(d);
	}
	else if (isFloat) {
		float f = std::stof(str);
		printFloat(f);
	}
	else {
		int i = str::stoi(str);
		printInt(i);
	}
}

void	ScalarConverter::convert(std::string str) {
	std::string spe[3] = {"-inf", "+inf", "nan"};
	std::string speF[3] = {"-inff", "+inff", "nanf"};

	bool	isSpe = false;

	if (strcmp(str.c_str(), "nan") || strcmp(str.c_str(), "nanf")) {
		printErr("not a number");
	}
	
	for (int i = 0; i < 3; i++) {
		if ((str == spe[i] || str == speF[i])) {
			printSpe(str);
			isSpe = true;
		}
	}
	if (!isSpe)
		getType(str);
}
