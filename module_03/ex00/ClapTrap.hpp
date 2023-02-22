#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
  public:
	// Constructors
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);

	// Destructor
	~ClapTrap();

	// Operators
	ClapTrap &operator=(const ClapTrap &assign);

	//functions
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//get
	std::string getName() const;
	int	getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;

  private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
};

#endif