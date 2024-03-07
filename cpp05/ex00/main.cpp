#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat test("bob");
	test.setGrade(151);

//	std::cout << test.getName() << std::endl;
//	std::cout << test.getGrade() << std::endl;
	std::cout << test << std::endl;
}
