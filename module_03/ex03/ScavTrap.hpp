#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"
class ScavTrap: virtual public ClapTrap
{
  public: 
	// Constructors
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);

	// Destructor
	~ScavTrap();

	// Operators
	ScavTrap &operator=(const ScavTrap &assign);

	//functions
	void guardGate();
	void attack(const std::string &target);
};

#endif