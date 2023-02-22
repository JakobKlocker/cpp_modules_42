#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

// WrongAnimal::WrongAnimal()
// {
// 	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
// }

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
	*this = copy;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}

// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "I'm an WrongAnimallll" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return(this->type);
}