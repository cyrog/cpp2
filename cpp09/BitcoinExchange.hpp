#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>

class	btcExchange {

	private:
		std::map<std::string, float>	_map;

	public:
		btcExchange();
		btcExchange(btcExchange const &src);
		~btcExchange();

		btcExchange	&operator=(btcExchange const &rhs);

		void	mapFiller(void);
};

#endif
