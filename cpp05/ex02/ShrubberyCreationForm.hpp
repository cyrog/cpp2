#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "AForm.hpp"
#include <string>

class	ShrubberyCreationForm : public Form {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(ShrubberyCreationForm const &src);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
};

#endif
