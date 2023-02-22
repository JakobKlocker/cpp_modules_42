#ifndef FragTrap_HPP
# define FragTrap_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"
class FragTrap: public ClapTrap
{
  public: 
	// Constructors
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);

	// Destructor
	~FragTrap();

	// Operators
	FragTrap &operator=(const FragTrap &assign);

	//functions
	void highFivesGuys();
	void attack(const std::string &target);
};

#endif