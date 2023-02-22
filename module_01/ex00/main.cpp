#include "Zombie.hpp"

int main()
{
    Zombie *ptr = NULL;
    std::cout << "Calling randomChump\n";
    ptr->randomChump("David");
    std::cout << "Calling newZombie\n";
    ptr = ptr->newZombie("Greg");
    delete ptr;
}
