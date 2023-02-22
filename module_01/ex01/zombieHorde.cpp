#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name)
{
    int i = 0;
    Zombie *ret = new Zombie[N];
    while(i < N)
    {
        ret[i].name = name;
        ret[i].announce();
        i++;
    }
    return ret;
}
