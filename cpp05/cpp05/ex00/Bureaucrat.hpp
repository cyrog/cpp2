#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class	Bureaucrat	{
	private:
		std::string	const	_name;
		int					_grade;	

		void	validGrade(int grade);
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat		&operator=(Bureaucrat const &rhs);


		void	setGrade(int newGrade);
		void	gradePlus();
		void	gradeMinus();

		int		getGrade() const;

		const std::string	&getName() const {
			return _name;
		}

	class	GradeTooHigh : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too high";
			}
	};

	class	GradeTooLow : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too low";
			}
	};
};

	std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif
