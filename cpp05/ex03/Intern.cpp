#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &src) {
	(void)src;
	*this = src;
}

Intern::~Intern() {
}

Intern	&Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

Form	*Intern::makeForm(std::string name, std::string target) {
	Form	*myForm = NULL;
	Form	*listFuncs[] = { Intern::formSCF(target), Intern::formRRF(target), Intern::formPPF(std::string target) };
	std::string	listForms[] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };

	for (i = 0; i < 3; i++) {
		if (name == listForms[i]) {
			std::cout << "l'esclave created the form: " << name << std::endl;
			myForm = listFuncs[i];
			return myForm;
		}
	}
	throw (Intern::formException());
}
