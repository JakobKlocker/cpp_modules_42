#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("name");

    a.getAttackDamage();
    a.beRepaired(4);
    a.attack("moulinette");
    a.takeDamage(3);
    ClapTrap b(a);
    a.takeDamage(12);
    a.takeDamage(12);
    b.takeDamage(4);
}
