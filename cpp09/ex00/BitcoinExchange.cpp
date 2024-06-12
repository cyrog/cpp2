#include "BitcoinExchange.hpp"

btcExchange::btcExchange() {
	std::ifstream	data("data.csv");
	std::string		line;

	if (!data)
		std::cerr << "error: data file" << std::endl;

	std::getline(data, line); //skip 1st line
	while (std::getline(data, line)) {
		std::string key = line.substr(0, line.find_first_of(","));
		float value = std::atof(line.substr(line.find_first_of(",") + 1).c_str());
		this->_db[key] = value;
	}
	data.close();
}

btcExchange::btcExchange(btcExchange const &src) {
	*this = src;
}

btcExchange::~btcExchange() {
}

btcExchange	&btcExchange::operator=(btcExchange const &rhs) {
	if (this != &rhs)
		this->_db= rhs._db;
	return *this;
}

bool btcExchange::isValidDate(const std::string &date) {
    if (date.length() != 10)
		return false;
    if (date[4] != '-' || date[7] != '-')
		return false;
    std::istringstream iss(date);
    int year, month, day;
    char dash1, dash2;
    if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return false;
    if (dash1 != '-' || dash2 != '-')
		return false;
    if (month < 1 || month > 12)
		return false;
    if (day < 1 || day > 31)
		return false; // Simplified check; not all months have 31 days
    return true;
}

bool btcExchange::isPositiveNumber(const std::string &str) {
    std::istringstream iss(str);
    double num;
    if (!(iss >> num))
		return false;
    return num > 0;
}

bool btcExchange::isValidValue(double value) {
	return value >= 0 && value <= 1000;
}

std::string btcExchange::findClosestDate(const std::string &date) {
    std::map<std::string, float>::iterator it = _db.lower_bound(date);
    if (it != _db.end() && it->first == date) {
        return date;
    }
    if (it == _db.begin()) {
        return "";
    }
    --it;
    return it->first;
}

void btcExchange::processInputFile(const std::string& filename) {
    std::ifstream input_file(filename.c_str());
    if (!input_file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        std::string date, value_str;
        if (std::getline(iss, date, '|') && std::getline(iss, value_str)) {
            date = date.substr(0, date.find_last_not_of(" ") + 1);
            value_str = value_str.substr(value_str.find_first_not_of(" "), value_str.size());

            if (!isValidDate(date)) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }

            if (!isPositiveNumber(value_str)) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }

            double value;
            std::istringstream(value_str) >> value;
            if (value > INT_MAX) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }

            if (!isValidValue(value)) {
                std::cout << "Error: value out of range => " << value << std::endl;
                continue;
            }

            std::string closest_date = findClosestDate(date);
            if (closest_date.empty()) {
                std::cout << date << " => " << value << " = unknown rate" << std::endl;
            } else {
                double rate = _db[closest_date];
                double result = value * rate;
                std::cout << date << " => " << value << " = " << result << std::endl;
            }
        }
    }

    input_file.close();
}