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
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat		&operator=(Bureaucrat const &rhs);

		friend std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs);

		void	setGrade(int newGrade);

		int	getGrade() const {
			return _grade;
		}

		const std::string	&getName() const {
			return _name;
		}

	class	GradeTooHigh : public std::exception {
		public:
			GradeTooHigh() : std::exception() {
				std::cerr << "Grade is too damn high" << std::endl;
			}
	};

	class	GradeTooLow : public std::exception {
		public:
			GradeTooLow() : std::exception() {
				std::cerr << "Grade is too damn low" << std::endl;
			}
	};
};

#endif
