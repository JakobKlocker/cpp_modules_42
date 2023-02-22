#include "HumanB.hpp"
HumanB::HumanB(std::string name) : wep(NULL), name(name)
{
    HumanB::name = name;
}

// HumanB::~HumanB()
// {
// 	if(HumanB::wep != NULL)
// 		free(HumanB::wep);
// }

void HumanB::attack()
{
	std::cout << HumanB::name << " attacks with their " << HumanB::wep->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &wep)
{
	HumanB::wep = &wep;
}
