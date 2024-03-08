#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class	Form {
	private:
		std::string	const	_name;
		bool				_signed;
		int					_reqSign;
		int					_reqExec;
	
	public:
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
