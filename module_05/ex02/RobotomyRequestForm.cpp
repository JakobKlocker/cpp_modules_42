#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy", 72, 45)
{
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy", 72, 45), target(target)
{
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy)
	: AForm(copy.getName(), 72, 45), target(copy.target)
{
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	this->setIsSigned(assign.getIsSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "Destructor called on " << this->getName() << std::endl;
}

// std::string RobotomyRequestForm::getTarget()
// {
//     return (this->target);
// }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == 0)
		throw RobotomyRequestForm::NotSignedException();
	else if (executor.getGrade() > this->getExeGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	static unsigned int counter = 0;
	if(counter % 2 == 0)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << " robotomy failed" << std::endl;
	counter++;
}