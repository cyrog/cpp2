#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	Bureaucrat::validGrade(int grade) {
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
}

Bureaucrat::Bureaucrat() : _name("default") {
//	std::cout << "default bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name) {
//	std::cout << "string bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {
//	std::cout << "copy bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
//	std::cout << "bureaucrat destructor called" << std::endl;
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
	try {
		_grade = newGrade;
		validGrade(newGrade);
	}
	catch (const GradeTooHigh &e) {
		std::cerr << "grade is too damn high" << std::endl;
		_grade = 1;
	}
	catch (const GradeTooLow &e) {
		std::cerr << "grade is too damn low" << std::endl;
		_grade = 150;
	}
}

void	Bureaucrat::gradePlus(void) {
	try {
		_grade--;
		validGrade(_grade);
	}
	catch (const GradeTooHigh &e) {
		std::cerr << "cant increment grade cause it's too damn high" << std::endl;
		_grade = 1;
	}
}

void	Bureaucrat::gradeMinus(void) {
	try {
		_grade++;
		validGrade(_grade);
	}
	catch (const GradeTooLow &e) {
		std::cerr << "cant decrement grade cause it's too damn low" << std::endl;
		_grade = 150;
	}
}

int		Bureaucrat::getGrade() const {
	try {
		if (_grade < 1)
			throw GradeTooHigh();
		else if (_grade > 150)
			throw GradeTooLow();
	}
	catch (const GradeTooHigh &e) {
		std::cerr << "cant getGrade cause its too damn high" << std::endl;
		return (1);
	}
	catch (const GradeTooLow &e) {
		std::cerr << "cant getGrade cause its too damn low" << std::endl;
		return (150);
	}
	return _grade;
}

void		Bureaucrat::signForm(Form &form) {
	try {
		form.signing(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &e) {
		std::cout << this->getName() << " couldn't sign the form " << form.getName() << " because grade is too low" << std::endl;
	}
}
