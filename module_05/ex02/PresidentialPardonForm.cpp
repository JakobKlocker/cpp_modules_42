#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential", 25, 5)
{
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential", 25, 5), target(target)
{
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy)
	: AForm(copy.getName(), 25, 5), target(copy.target)
{
	//std::cout << "Constructor called on " << this->getName() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	this->setIsSigned(assign.getIsSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "Destructor called on " << this->getName() << std::endl;
}

// std::string PresidentialPardonForm::getTarget()
// {
//     return (this->target);
// }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == 0)
		throw PresidentialPardonForm::NotSignedException();
	else if (executor.getGrade() > this->getExeGrade())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}