#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
  private:
	Weapon &wep;
	std::string name;

  public:
	HumanA(std::string name, Weapon &wep);
	void attack();
};

#endif