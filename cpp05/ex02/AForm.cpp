#include "AForm.hpp"

Form::Form() : _name("default"), _signed(0), _reqSign(30), _reqExec(120) {
}

Form::Form(std::string name) : _name(name), _signed(0), _reqSign(30), _reqExec(120) {
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _reqSign(src._reqSign), _reqExec(src._reqExec) {
}

Form::Form(std::string name, bool signd, int reqSign, int reqExec) : _name(name), _signed(signd), _reqSign(reqSign), _reqExec(reqExec) {
	checkGrade();
}

Form::~Form() {
}

Form	&Form::operator=(Form const &rhs) {
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Form const &rhs) {

	os << "Form name: " << rhs.getName() << std::endl;
	if (rhs.getSigned() == 0)
		os << "Form state: " << "unsigned" << std::endl;
	else if (rhs.getSigned() == 1)
		os << "Form state: " << "signed" << std::endl;
	os << "Grade required to sign: " << rhs.getReqSign() << std::endl;
	os << "Grade required to exec: " << rhs.getReqExec() << std::endl;
	os << "_________________________" << std::endl;

	return os;
}

void	Form::checkGrade() {
	if (_reqSign < 1 || _reqExec < 1)
		throw (gradeHigh());
	else if (_reqSign > 150 || _reqExec > 150)
		throw (gradeLow());
	else
		_allowed = true;
}

void	Form::signing(Bureaucrat &buro) {
	if (buro.getGrade() > _reqSign)
		throw (Form::gradeLow());
	else {
		_signed = true;
		_allowed = true;
	}
}

bool	Form::allowed(int grade) const {
	if (grade > this->getReqSign() || grade > this->getReqExec())
		return false;
	return true;
}
