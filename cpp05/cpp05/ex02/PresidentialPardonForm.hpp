#ifndef PRESIDENT
# define PRESIDENT

#include "AForm.hpp"
#include <unistd.h>

class	PresidentialPardonForm : public Form {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

		std::string	getTarget() {
			return this->_target;
		}


		void	execute(Bureaucrat const &buro) const;
};

#endif
