#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(RobotomyRequestForm &copy);
    RobotomyRequestForm(std::string name, int signGrade, int exeGrade);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);

    ~RobotomyRequestForm();
    void execute(Bureaucrat const & executor) const;

    private:
    std::string target;
};