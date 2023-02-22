#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("daniel");
    a.beRepaired(4);
    a.attack("moulinette");
    a.takeDamage(3);
    a.guardGate();
    ClapTrap b("clappy");
    b.beRepaired(4);
    b.attack("moulinette");
    b.takeDamage(3);
}
