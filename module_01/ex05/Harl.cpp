#include "Harl.hpp"

void Harl::complain(std::string level)
{
    // void (Harl::* deb) (void) = &Harl::debug;
    // void (Harl::* inf) (void) = &Harl::info;
    // void (Harl::* war) (void) = &Harl::warning;
    // void (Harl::* err) (void) = &Harl::error;
    void (Harl::* funcs[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    // std::string debug = "DEBUG";
    // std::string info = "INFO";
    // std::string warrning = "WARNING";
    // std::string error = "ERROR";
    std::string msgs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for(int i = 0; i < 4; i++)
    {
        if(msgs[i] == level)
        {
            (this->*funcs[i])();
            break ;
        }
    }
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put ";
    std:: cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ";
    std::cout << "years whereas you started working here since last month" << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
