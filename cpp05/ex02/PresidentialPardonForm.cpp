#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Pres", false, 25, 5) {
	_target = target;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src.getName(), src.getSigned(), src.getReqSign(), src.getReqExec()) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	Form::operator=(*this);
	this->_target = rhs._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &buro) const {
	if (!this->allowed(buro.getGrade()))
		throw(gradeLow());
	PresidentialPardonForm copy = *this;
	std::cout << copy.getTarget() << " has been pardoned by Macron" << std::endl;

	sleep(2);
	std::cout << "* explosion *" << std::endl;
}
