#include "Span.hpp"

Span::Span() : _nb(0), _N(0) {}

Span::Span(unsigned int n) : _nb(0), _N(n) {}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span() {}

Span	&Span::operator=(Span const &rhs) {
	this->_nb = rhs._nb;
	this->_N = rhs._N;
	return *this;
}

void	Span::addNumber(int i) {
	if (_nb.size() >= _N)
		throw std::overflow_error("max size reached");
	_nb.push_back(i);
}

int		Span::getNumber(int index) {
	return _nb[index];


}

unsigned int		Span::shortestSpan(void) {

	unsigned int	min;
	unsigned int	temp;
	unsigned long i;

	if (_nb.size() <= 1)
		throw tooShort();
	std::sort(_nb.begin(), _nb.end());

	min = _nb[1] - _nb[0];

	for (i = 1; i < _nb.size(); i++) {
		temp = _nb[i] - _nb[i - 1];
		if (temp < min)
			min = temp;
			
	}
	std::cout << "min found: " << min << std::endl;

	return min;
}

unsigned int		Span::longestSpan(void) {

	unsigned int	max;
	unsigned int	temp;
	unsigned long 	i;

	if (_nb.size() <= 1)
		throw tooShort();
	std::sort(_nb.begin(), _nb.end());

	max = _nb[1] - _nb[0];

	for (i = 1; i < _nb.size(); i++) {
		temp = _nb[i] - _nb[i - 1];
		if (temp > max)
			max = temp;
	}

	std::cout << "size = " << _nb.size() << std::endl;
	std::cout << "iterator value at end: " << i << std::endl;
	std::cout << "max found: " << max << std::endl;

	return max;
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + _nb.size() > _N) {
		throw std::overflow_error("max size reached");
	}
	_nb.insert(_nb.end(), begin, end);
}

/*void	Span::genRandom(unsigned int const size) {

	std::srand(std::time(NULL));

	for (unsigned int i = 0; i < size; i++) {
		int	randNb = std::rand();
		_nb.push_back(randNb);
	}
	for (unsigned int i = 0; i < size; i++) {
		std::cout << _nb[i] << std::endl;
	}
}
*/
