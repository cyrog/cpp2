#include "Bureaucrat.hpp"

void	Bureaucrat::validGrade(int grade) {
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
}

Bureaucrat::Bureaucrat() : _name("default") {
	std::cout << "default bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name) {
	std::cout << "string bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {
	std::cout << "copy bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this == &rhs)
		return *this;
	setGrade(rhs.getGrade());
	return *this;
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &rhs) {
	os << "Bureaucrat " << rhs._name << " has grade " << rhs._grade;
	return os;
}

void	Bureaucrat::setGrade(int newGrade) {
	validGrade(newGrade);
	_grade = newGrade;
}
