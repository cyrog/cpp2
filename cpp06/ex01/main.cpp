#include "Serializer.hpp"

void	initPG(Data *pg) {
	pg->name = "pg";
	pg->alcool = 5.3;
	pg->price = 0.5;
	pg->rate = 10;
}

void	printAlcool(Data *pg) {
	std::cout << "name: " << pg->name << std::endl;
	std::cout << "alcool percentage: " << pg->alcool << std::endl;
	std::cout << "price: " << pg->price << std::endl;
	std::cout << "rate: " << pg->rate << std::endl;
}

int	main(void) {

	Data	PG;

	initPG(&PG);

	std::cout << "______ base values _________" << std::endl;
	printAlcool(&PG);


	std::cout << "______ serialized values _________" << std::endl;
	uintptr_t serialized = Serializer::serialize(&PG);
	std::cout << "beer value serialized: " << serialized << std::endl;

	Data	*newAlcool = Serializer::deserialize(serialized);

	std::cout << std::endl << "______ deserialized values _________" << std::endl;
	printAlcool(newAlcool);


	return 0;

}
