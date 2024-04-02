#include "ABC.hpp"
#include "Base.hpp"

Base	*generate(void) {
	std::srand(time(NULL));
	int	random = rand() % 3;

	switch(random) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void	identify(Base *p) {
	if (A *a = dynamic_cast<A*>(p))
		std::cout << "this pointer is class A" << std::endl;
	else if (B *b = dynamic_cast<B*>(p))
		std::cout << "this pointer is class B" << std::endl;
	else if (C *c = dynamic_cast<C*>(p))
		std::cout << "this pointer is class C" << std::endl;
	else
		std::cout << "unknown class" << std::endl;
}

void	identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "this ref is class A" << std::endl;
		return ;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "this ref is class B" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "this ref is class C" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
}

int	main(void) {
	Base	*test;
	test = generate();
	identify(test);
	identify(*test);
	delete(test);

	return 0;

}
