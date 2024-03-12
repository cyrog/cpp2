#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
	private:
		std::string	const	_name;
		bool				_signed;
		int					_reqSign;
		int					_reqExec;
	
	public:
		Form();
		Form(std::string name);
		Form(std::string name, bool signd, int reqSign, int reqExec);
		Form(Form const &src);
		~Form();

		Form	&operator=(Form const &rhs);

		friend std::ostream	&operator<<(std::ostream &os, Form const &rhs);

		class gradeHigh : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "grade too high";
				}
		};

		class	gradeLow : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "grade too low";
				}
		};

		std::string	getName() {
			return _name;
		}

		bool		getSigned() {
			return _signed;
		}

		int			getReqSign() {
			return _reqSign;
		}

		int			getReqExec() {
			return _reqExec;
		}
};

#endif
