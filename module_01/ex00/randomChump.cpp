#include "Zombie.hpp"

void    Zombie::randomChump (std::string name)
{
    Zombie zomb(name);
    zomb.announce();
}
