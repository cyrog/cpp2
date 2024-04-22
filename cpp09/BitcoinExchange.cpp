#include "BitcoinExchange.hpp"

btcExchange::btcExchange() {
}

btcExchange::btcExchange(btcExchange const &src) : _map(src._map) {
}

btcExchange::~btcExchange() {
}

btcExchange	&btcExchange::operator=(btcExchange const &rhs) {
	if (this != &rhs)
		this->_map = rhs._map;
	return *this;
}
