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
		bool			_signed;
		int		const	_reqSign;
		int		const	_reqExec;

		bool			_allowed;
	
	public:
		Form();
		Form(std::string name);
		Form(std::string name, bool signd, int reqSign, int reqExec);
		Form(Form const &src);
		virtual ~Form();

		Form	&operator=(Form const &rhs);

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

		void	checkGrade();
		void	signing(Bureaucrat &buro);
		
		bool	allowed(int grade) const;

		std::string	getName() const {
			return this->_name;
		}

		bool		getSigned() const {
			return this->_signed;
		}

		int			getReqSign() const {
			return this->_reqSign;
		}

		int			getReqExec() const {
			return this->_reqExec;
		}

		bool		getAllowed() const {
			return this->_allowed;
		}

		virtual void	execute(Bureaucrat const &buro) const = 0;
};
	std::ostream	&operator<<(std::ostream &os, Form const &rhs);

#endif
