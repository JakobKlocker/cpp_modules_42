#include "Dog.hpp"

// Constructors
Dog::Dog() : Animal()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->type = assign.type;
	delete this->brain;
	this->brain = new Brain(*assign.brain);
	return *this;
}

void Dog::setIdea(const std::string &test)
{
	this->brain->setIdea(test);
}

void Dog::makeSound() const
{
	std::cout << "Wuff" << std::endl;
}