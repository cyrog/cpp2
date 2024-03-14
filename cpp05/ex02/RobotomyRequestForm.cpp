#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) Form("Shrub", false, 145, 137) {
	_target = target;
}


