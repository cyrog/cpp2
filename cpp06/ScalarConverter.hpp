#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <cstring>


class	ScalarConverter	{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter const &rhs);

		void	convChar(char nb);
		void	convInt(int nb);
		void	convFloat(float nb);
		void	convDouble(double nb);

		void	printChar(char nb);
		void	printInt(int nb);
		void	printFloat(float nb);
		void	printDouble(double nb);

		void	printSpe(std::string spe);
		void	printErr(std::string msg);
		
		void	getType(std::string str);
	
	public:
		static void	convert(std::string str);

};

#endif
