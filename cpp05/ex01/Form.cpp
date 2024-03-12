#include "Form.hpp"

Form::Form() : _name("default"), _signed(0), _reqSign(30), _reqExec(120) {
}

Form::Form(std::string name) : _name(name), _signed(0), _reqSign(30), _reqExec(120) {
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _reqSign(src._reqSign), _reqExec(src._reqExec) {
}

Form::Form(std::string name, bool signd, int reqSign, int reqExec) : _name(name) {
	_signed = signd;
	_reqSign = reqSign;
	_reqExec = reqExec;
}

Form::~Form() {
}

Form	&Form::operator=(Form const &rhs) : _name(rhs._name) {
	if (this == &rhs)
		return *this;

	return *this;
}


