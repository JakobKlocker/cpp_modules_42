#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include <iostream>
# include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
  public: 
	// Constructors
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);

	// Destructor
	~DiamondTrap();

	// Operators
	DiamondTrap &operator=(const DiamondTrap &assign);

	//functions
	void attack(const std::string &target);
	void whoAmI();
	private:
		std::string name;
};

#endif