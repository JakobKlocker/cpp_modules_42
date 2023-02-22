#ifndef Intern_HPP
# define Intern_HPP
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
    Intern();
    Intern(Intern &copy);

    Intern &operator=(const Intern &assign);

    ~Intern();
    AForm *makeForm(std::string formName, std::string target);
};

#endif