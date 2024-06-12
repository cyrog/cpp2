#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "error: usage > ./btc <input file>" << std::endl;
		return -1;
	}
	btcExchange btc;
	btc.processInputFile(argv[1]);

	return 0;
}