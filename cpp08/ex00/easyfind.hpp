#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

class	notFound : public std::exception {

	public:
		virtual const char* what() const throw() {
			return "not found";
		}
};

template<typename T>
void	easyfind(T &container, int nb) {

	typename T::iterator it;

	it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw notFound();
	//std::cout << *it << std::endl; //prints the found value
	std::cout <<(it - container.begin()) << std::endl;
	//std::cout << (std::distance(container.begin(), it)) << std::endl; //works as well, just different
}


#endif
