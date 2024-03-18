#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class	Intern {
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern	&operator=(Intern const &rhs);

		Form	*makeForm(std::string formName, std::string formTarget);

		Form	*formSCF(std::string target) {
			return new ShrubberyCreationForm(target);
		}
		Form	*formRRF(std::string target) {
			return new RobotomyRequestForm(target);
		}
		Form	*formPPF(std::string target) {
			return new PresidentialPardonForm(target);
		}

		class	formException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "form not found";
				}

		};

};

#endif
