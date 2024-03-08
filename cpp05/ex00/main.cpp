#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat bob("bob");
	bob.setGrade(150);
	bob.gradeMinus();
	std::cout << bob << std::endl;
//	bob.gradePlus();

	//std::cout << "Bureaucrat name is: " << bob.getName() << std::endl;
	//std::cout << "Bureaucrat Grade is: " << bob.getGrade() << std::endl;
	std::cout << bob << std::endl;
	std::cout << "________________________" << std::endl;
}
