#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    Weapon::type = str;
}

const std::string &Weapon::getType()
{
    const std::string &ret = Weapon::type;
    return (ret);
}

void    Weapon::setType(std::string str)
{
    Weapon::type = str;
}
