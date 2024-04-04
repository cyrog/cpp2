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
	//std::cout << "number: " << nb << std::endl;

	if ((nb < 32 || nb == 127) && !(nb >= '0' && nb <= '9'))
		std::cout << "char: non displayable character" << std::endl;
	else if (nb < 0 || nb > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << nb << std::endl;
}

void	ScalarConverter::convInt(int nb) {
	if (nb > INT_MAX || nb < INT_MIN)
		std::cout << "int: out of range" << nb << std::endl;
	else
		std::cout << "int: " << nb << std::endl;
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
	std::cout << "error: " << msg << std::endl;
}

void	ScalarConverter::printOutrange(std::string msg) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << msg << std::endl;
	std::cout << "float: " << msg << std::endl;
	std::cout << "double: " << msg << std::endl;
}

void	ScalarConverter::getType(std::string str) {
	bool			isDouble = false;
	bool			isFloat = false;
	//std::stringstream	ss(str);

	if (str.empty())
		return printErr("no input");
	if (str.size() > 10 || (str.size() == 10 && str > "2147483647") 
			|| (str.size() == 11 && str[0] == '-' && str.substr(1) > "2147483648"))
		return printOutrange("out of range");
	if (std::isalpha(str[0]) && str.size() == 1)
		return printChar(str[0]);
	for (int i = 0; i < (int)str.length(); i++) {
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (std::isdigit(str[i]))
			continue;
		if (str[i] == '.' && !isDouble)
			isDouble = true;
		else if (str[i] == 'f' && isDouble == true && isFloat == false) {
			isDouble = false;
			isFloat = true;
		}
		else
			return printErr("conversion impossible");
	}
	if (isDouble) {
		//double d = std::stod(str); //stof is c++11 sadge
		//printDouble(d);
		double d = atof(str.c_str());
		printDouble(d);
	}
	else if (isFloat) {
		//float f = std::stof(str);
		//printFloat(f);
		float f = atof(str.c_str());
		printFloat(f);
	}
	else {
		//int i = str::stoi(str); //c++11 aswell
		//printInt(i);
		int	i = atoi(str.c_str());
		printInt(i);
	}
}

void	ScalarConverter::convert(std::string str) {
	std::string spe[3] = {"-inf", "+inf", "nan"};
	std::string speF[3] = {"-inff", "+inff", "nanf"};

	bool	isSpe = false;

	if (std::isalpha(str[0]) && std::isalpha(str[1]) && strcmp(str.c_str(), "nan") && strcmp(str.c_str(), "nanf")) {
		return printErr("not a number");
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
