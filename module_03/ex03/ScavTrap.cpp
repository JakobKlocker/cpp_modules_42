#include "ScavTrap.hpp"
#include <iostream>
#include <stdlib.h>
// Constructors
ScavTrap::ScavTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "\e[0;33mName Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

// Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	ClapTrap::operator=(assign);
	return (*this);
}

//functions

void ScavTrap::guardGate()
{
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << this->getName() << " can't guard because he's dead." << std::endl;
		return ;
	}
	std::cout << this->getName() << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
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
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " damage!" << std::endl;
}
