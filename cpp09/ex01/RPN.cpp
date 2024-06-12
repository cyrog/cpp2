#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN::~RPN() {}

RPN	&RPN::operator=(RPN const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}


// Fonction pour vérifier si une chaîne est un opérateur
bool RPN::isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// Fonction pour effectuer les opérations arithmétiques
int RPN::performOperation(const std::string &operatorToken, int operand1, int operand2) {
    if (operatorToken == "+")
		return operand1 + operand2;
    if (operatorToken == "-")
		return operand1 - operand2;
    if (operatorToken == "*")
		return operand1 * operand2;
    if (operatorToken == "/") {
        if (operand2 == 0) {
            throw std::runtime_error("Division by zero");
        }
        return operand1 / operand2;
    }
    throw std::runtime_error("Invalid operator");
}

// Fonction principale pour évaluer l'expression RPN
int RPN::evaluateRPN(const std::string &expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::atoi(token.c_str()));
        } else if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Insufficient operands");
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            int result = performOperation(token, operand1, operand2);
            stack.push(result);
        } else {
            throw std::runtime_error("Invalid token");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    return stack.top();
}