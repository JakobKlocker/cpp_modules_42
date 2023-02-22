#include "FragTrap.hpp"
#include <iostream>
#include <stdlib.h>
// Constructors
FragTrap::FragTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "\e[0;33mName Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}

// Operators
FragTrap &FragTrap::operator=(const FragTrap &assign)
{
	ClapTrap::operator=(assign);
	return (*this);
}

//functions

void FragTrap::highFivesGuys()
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << this->getName() << " can't high five, he's dead." << std::endl;
		return ;
	}
	std::cout << this->getName() << " High Fives everybody." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << this->getName() << " has not enough energy points left." << std::endl;
		return ;
	}
	if (this->getHitPoints() <= 0)
	{
		std::cout << this->getName() << " can't be attacked becuase he's dead already." << std::endl;
		return ;
	}
	this->setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " damage!" << std::endl;
}
