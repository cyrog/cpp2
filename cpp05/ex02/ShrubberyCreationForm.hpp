#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>

class	ShrubberyCreationForm : public Form {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(ShrubberyCreationForm const &src);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		std::string	getTarget() {
			return this->_target;
		}

		void	execute(Bureaucrat const &buro) const;
};

#endif
