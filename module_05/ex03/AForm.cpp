#include "AForm.hpp"

// Constructors
AForm::AForm() : name("default"), signGrade(0),  exeGrade(0), isSigned(0)
{
	//std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(std::string name)
	: name(name), signGrade(0), exeGrade(0), isSigned(0)
{
	//std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(std::string name, int signGrade) : name(name), signGrade(signGrade), exeGrade(0), isSigned(0)
{
	if (this->signGrade > 150)
		throw AForm::GradeTooLowException();
	else if(signGrade < 1)
		throw AForm::GradeTooHighException();	
}

AForm::AForm(std::string name, int signGrade, int exeGrade) : name(name), signGrade(signGrade), exeGrade(exeGrade), isSigned(0)
{
	if (this->signGrade > 150)
		throw AForm::GradeTooLowException();
	else if(signGrade < 1)
		throw AForm::GradeTooHighException();	
}


AForm::AForm(const AForm &copy) : name(copy.getName()), signGrade(copy.getSignGrade()), exeGrade(copy.getExeGrade()), isSigned(copy.getIsSigned())
{
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
	*this = copy;
}

// Destructor
AForm::~AForm()
{
	//std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}

// Operators
AForm &AForm::operator=(const AForm &assign)
{
	//this->name = assign.name;
	this->isSigned = assign.isSigned;
	std::cout << "can't assign consts" <<std::endl;
	return (*this);
}

int AForm::getExeGrade() const
{
	return (this->exeGrade);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getSignGrade() const
{
	return (this->signGrade);
}

std::string AForm::getName() const
{
	return (this->name);
}

void	AForm::setIsSigned(bool Signed)
{
	this->isSigned = Signed;
}

std::ostream &operator<<(std::ostream &stream, const AForm &representation)
{
	return (stream << representation.getName() << ", grade required to execute: " 
	<< representation.getExeGrade() << ", grade required to sign: " 
	<< representation.getSignGrade() << ", is AForm signed (0 FALSE, 1 TRUE) " 
	<< representation.getIsSigned());
}

void AForm::beSigned(Bureaucrat &obj)
{
	if(obj.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade too Low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return("Form not signed");
}