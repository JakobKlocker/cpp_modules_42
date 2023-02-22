#include "ClapTrap.hpp"
#include <iostream>
#include <stdlib.h>
// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
	this->name = "default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "\e[0;33mName Constructor called of ClapTrap\e[0m" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}

// Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	this->name = assign.getName();
	this->hitPoints = assign.getHitPoints();
	this->energyPoints = assign.getEnergyPoints();
	this->attackDamage = assign.getAttackDamage();
	return (*this);
}

//functions

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << " has not enough energy points left." << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " can't be attacked becuase he's dead already." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " can't be attacked becuase he's dead already." << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " took " << amount << 
	" points of damage! " << this->name << " has " << this->hitPoints << " left" << std::endl;
	;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << " has not enough energy points left." << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " has no hitPoints left." << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repaired " << amount << " points of health! " << this->name << 
	" has " << this->hitPoints << " healthpoints now" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}
