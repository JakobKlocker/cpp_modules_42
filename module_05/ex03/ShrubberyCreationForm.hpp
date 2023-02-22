#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(ShrubberyCreationForm &copy);
    ShrubberyCreationForm(std::string name, int signGrade, int exeGrade);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);

    ~ShrubberyCreationForm();
    void execute(Bureaucrat const & executor) const;

    private:
    std::string target;
};
#endif