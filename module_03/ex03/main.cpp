#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    FragTrap x("Fragy");
    x.beRepaired(4);
    x.attack("moulinette");
    x.takeDamage(3);
    x.highFivesGuys();
    ScavTrap a("Scavy");
    a.beRepaired(4);
    a.attack("moulinette");
    a.takeDamage(3);
    a.guardGate();
    ClapTrap b("Clapy");
    b.beRepaired(4);
    b.attack("moulinette");
    b.takeDamage(3);

    DiamondTrap trap("Diamondyyy");
    trap.beRepaired(4);
    trap.attack("moulinette");
    trap.takeDamage(3);
    trap.attack("Moulinette");
    trap.whoAmI();
}
