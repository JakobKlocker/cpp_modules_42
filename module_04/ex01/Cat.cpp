#include "Cat.hpp"

// Constructors
Cat::Cat() : Animal()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.type;
	delete this->brain;
	this->brain = new Brain(*assign.brain);
	return *this;
}

void Cat::setIdea(const std::string &test)
{
	this->brain->setIdea(test);
}

void Cat::printIdeaAddr()
{
	std::cout << this->brain << std::endl;
}

void Cat::printIdea()
{
	this->brain->printIdea();
}

void Cat::makeSound() const
{
	std::cout << "Miauuu" << std::endl;
}