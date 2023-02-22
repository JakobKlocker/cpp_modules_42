#include "DiamondTrap.hpp"
#include <iostream>
#include <stdlib.h>
// Constructors
DiamondTrap::DiamondTrap()
{
	std::string tmp = "Default";
	this->name = tmp;
	this->setName(tmp + "_clap_name");
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->setName(name + "_clap_name");
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "\e[0;33mName Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}

// Operators
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &assign)
{
	ScavTrap::ClapTrap::operator=(assign);
	return (*this);
}

//functions
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Diamond name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << this->getName() << std::endl;
}
