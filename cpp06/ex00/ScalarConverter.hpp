#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <climits>
#include <iomanip>
#include <cstring>
#include <sstream>


class	ScalarConverter	{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter const &rhs);

		static void	convChar(char nb);
		static void	convInt(int nb);
		static void	convFloat(float nb);
		static void	convDouble(double nb);

		static void	printChar(char nb);
		static void	printInt(int nb);
		static void	printFloat(float nb);
		static void	printDouble(double nb);

		static void	printSpe(std::string spe);
		static void	printErr(std::string msg);
		static void	printOutrange(std::string msg);
		
		static void	getType(std::string str);
	
	public:
		static void	convert(std::string str);

};

#endif
