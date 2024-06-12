#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class	RPN {
	private:
		bool	isOperator(const std::string &token);
		int		performOperation(const std::string &operatorToken, int operand1, int operand2);

	public:
		RPN();
		RPN(RPN const &src);
		~RPN();

		RPN	&operator=(RPN const &rhs);

		int		evaluateRPN(const std::string &expression);
};

#endif