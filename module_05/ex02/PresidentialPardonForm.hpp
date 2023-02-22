#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(PresidentialPardonForm &copy);
    PresidentialPardonForm(std::string name, int signGrade, int exeGrade);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);

    ~PresidentialPardonForm();
    void execute(Bureaucrat const & executor) const;

    private:
    std::string target;
};