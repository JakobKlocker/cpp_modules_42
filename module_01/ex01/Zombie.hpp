#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <stdlib.h>
# include <string>

class Zombie
{
  private:
	std::string name;

  public:
	Zombie();
	Zombie(std::string name);
	void announce();
	Zombie *newZombie(std::string name);
	Zombie *zombieHorde(int N, std::string name);
	void randomChump(std::string name);
	~Zombie();
};

#endif