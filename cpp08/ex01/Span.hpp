#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

class	Span {
	private:
		std::vector<int>	_nb;
		unsigned int		_N;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span();

		Span	&operator=(Span const &rhs);

		int		getNumber(int index);

		void	addNumber(int i);

		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);

		void	printAll(void);

		class	tooShort : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "container too short";
			}
		};

//		void	genRandom(unsigned int const size);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

#endif
