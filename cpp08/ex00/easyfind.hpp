#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class	NotFoundExcept : public std::exception {

	const char *what() const throw() {
		return ("No occurence found");
	}
};

template<typename T>
typename	T::iterator	easyfind(T &container, int nb) {

	typename	T::iterator it;

	it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw NotFoundExcept();
	std::cout << "Occurence of " << nb << " found in pos: " << (std::distance(container.begin(), it) + 1) << std::endl;
	return (it);
}

#endif
