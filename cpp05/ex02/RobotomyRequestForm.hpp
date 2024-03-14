#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMY_REQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public Form {
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
};

#endif
