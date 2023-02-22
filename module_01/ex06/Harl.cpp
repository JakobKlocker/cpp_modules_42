#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string msgs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (msgs[i] == level)
		{
			print(i);
			break ;
		}
	}
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    std::exit(0);
}

void	Harl::print(int i)
{
	switch (i)
	{
        case 0:
        std::cout << "[DEBUG]" << std::endl;
        std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
        case 1:
        std::cout << "[INFO]" << std::endl;
        std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put" <<
            " enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
        case 2:
            std::cout << "[WARNING]" << std::endl;
        	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for " 
            << "years whereas you started working here since last month" << std::endl << std::endl;
        case 3:
            std::cout << "[ERROR]" << std::endl;
            std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
            std::exit(0);
        default:
            break;
	}
}
