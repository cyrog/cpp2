#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Shrub", false, 72, 45) {
	_target = target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	Form::operator=(*this);
	this->_target = rhs._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src.getName(), src.getSigned(), src.getReqSign(), src.getReqExec()) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(Bureaucrat const &buro) const {
	if (!this->allowed(buro.getGrade()))
		throw(gradeLow());
	RobotomyRequestForm	copy = *this;
	std::cout << "* 10 *" << std::endl;
	sleep(1);
	std::cout << "* 12 *" << std::endl;
	sleep(1);
	std::cout << "* 14 *" << std::endl;
	sleep(1);
	std::cout << "* buro *" << std::endl;
	sleep(1);
	std::cout << "* ... *" << std::endl;


	std::srand(std::time(0));	//seed random number at current time
	int	randomNumber = std::rand() % 2;	//generate a 0 or a 1
	
	if (randomNumber == 0)
		std::cout << copy.getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << copy.getTarget() << " robotomization failed, try again" << std::endl;
}
