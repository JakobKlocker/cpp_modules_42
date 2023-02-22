#include "Intern.hpp"

Intern::Intern()
{
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

Intern::Intern(Intern &copy)
{
	(void)copy;
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

Intern &Intern::operator=(const Intern &assign)
{
	(void)assign;
	return (*this);
}

Intern::~Intern()
{
	//std::cout << "Destructor called on " << this->getName() << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {"robotomy request", "shrubbery request", "presidental request"};

	for(int i = 0; i < 3; i++)
	{
		if(forms[i] == formName)
		{
			switch(i)
			{
				AForm *ret;
				case 0:
					std::cout << "Intern creates form Robotomy" << std::endl;
					ret = new RobotomyRequestForm(target);
					return ret;
				case 1:
					std::cout << "Intern creates form Shrubbery" << std::endl;
					ret = new ShrubberyCreationForm(target);
					return ret;
				case 2:
					std::cout << "Intern creates form Presidential" << std::endl;
					ret = new PresidentialPardonForm(target);
					return ret;
				default:
					std::cout << "Form Name not found!" << std::endl;
					return NULL;
			}
		}
	}
	std::cout << "Form Name not found!" << std::endl;
	return NULL;
}
