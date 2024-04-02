#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct	Data {
	std::string	name;
	float		alcool;
	float		price;
	int		rate;
};


class	Serializer {
	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();

		Serializer	&operator=(const Serializer &rhs);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);
};

#endif
