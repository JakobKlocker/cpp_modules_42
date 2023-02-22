#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
  private:
	Weapon *wep;
	std::string name;

  public:
	void	setWeapon(Weapon &wep);
	void 	attack();
	HumanB(std::string name);
	// ~HumanB();
};

#endif
