#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wep) : wep(wep)
{
    HumanA::name = name;
    HumanA::wep = wep;
}

void HumanA::attack()
{
    std::cout << HumanA::name << " attacks with their " << HumanA::wep.getType() << std::endl;
}
