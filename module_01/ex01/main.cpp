#include "Zombie.hpp"

int main()
{
    std::cout << "Calling zombieHord, N = 100\n";
    Zombie *tmp = NULL;
    
    tmp = tmp->zombieHorde(10, "Daniel");
    delete[] tmp;
}
