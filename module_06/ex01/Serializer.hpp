#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct Data
{
	int i;
	char ch;
}Data;


class Serializer
{
	public:
		// Constructors
		Serializer();
		Serializer(const Serializer &copy);
		
		// Destructor
		~Serializer();
		
		// Operators
		Serializer & operator=(const Serializer &assign);
		
		Data* deserialize(uintptr_t raw);
		uintptr_t serialize(Data* ptr);
	private:
		
};

#endif