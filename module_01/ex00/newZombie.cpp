#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name)
{
    Zombie *zomb = new Zombie;
    zomb->name = name;
    zomb->announce();
    return (zomb);
}
