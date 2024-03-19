#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {

	Intern	defaultIntern;

	Form	*shrubForm;
	Form	*roboForm;
	Form	*prezForm;

	Form	*paslaForm;

	try {
		shrubForm = defaultIntern.makeForm("ShrubberyCreationForm", "shrub_place");
		roboForm = defaultIntern.makeForm("RobotomyRequestForm", "boombot");
		prezForm = defaultIntern.makeForm("PresidentialPardonForm", "gueux");

		paslaForm = defaultIntern.makeForm("paslaForm", "nowhere");

		std::cout << *shrubForm << std::endl;
		std::cout << *roboForm << std::endl;
		std::cout << *prezForm << std::endl;

		std::cout << *paslaForm << std::endl;

		delete shrubForm;
		delete roboForm;
		delete prezForm;
		delete paslaForm;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
