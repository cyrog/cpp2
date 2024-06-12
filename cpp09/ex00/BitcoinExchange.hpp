#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class	btcExchange {

	private:
		std::map<std::string, float>	_db;
		bool		isValidDate(const std::string &date);
		bool		isPositiveNumber(const std::string &str);
		bool		isValidValue(double value);
		std::string	findClosestDate(const std::string &date);

	public:
		btcExchange();
		btcExchange(btcExchange const &src);
		~btcExchange();

		btcExchange	&operator=(btcExchange const &rhs);

		void	processInputFile(const std::string &filename);
};

#endif
