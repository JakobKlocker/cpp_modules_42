#include "Zombie.hpp"

Zombie::Zombie()
{
    Zombie::name = "default";
}

Zombie::Zombie(std::string name)
{
    Zombie::name = name;
}

void Zombie::announce()
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    if(Zombie::name == "")
        return;
    std::cout << Zombie::name << "\n";
}
