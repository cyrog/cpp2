#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrub", false, 145, 137) {
	_target = "default";
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrub", false, 145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src.getName(), src.getSigned(), src.getReqSign(), src.getReqExec()) {
	*this = src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	Form::operator=(*this);
	return *this;
}
