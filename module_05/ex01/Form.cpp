#include "Form.hpp"

// Constructors
Form::Form() : name("default"), signGrade(0),  exeGrade(0), isSigned(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name)
	: name(name), signGrade(0), exeGrade(0), isSigned(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, int signGrade) : name(name), signGrade(signGrade), exeGrade(0), isSigned(0)
{
	if (this->signGrade > 150)
		throw Form::GradeTooLowException();
	else if(signGrade < 1)
		throw Form::GradeTooHighException();	
}

Form::Form(std::string name, int signGrade, int exeGrade) : name(name), signGrade(signGrade), exeGrade(exeGrade), isSigned(0)
{
	if (this->signGrade > 150)
		throw Form::GradeTooLowException();
	else if(signGrade < 1)
		throw Form::GradeTooHighException();	
}


Form::Form(const Form &copy) : name(copy.getName()), signGrade(copy.getSignGrade()), exeGrade(copy.getExeGrade()), isSigned(copy.getIsSigned())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form &Form::operator=(const Form &assign)
{
	//this->name = assign.name;
	this->isSigned = assign.isSigned;
	std::cout << "can't assign consts" <<std::endl;
	return (*this);
}

int Form::getExeGrade() const
{
	return (this->exeGrade);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

std::string Form::getName() const
{
	return (this->name);
}

std::ostream &operator<<(std::ostream &stream, const Form &representation)
{
	return (stream << representation.getName() << ", grade required to execute: " 
	<< representation.getExeGrade() << ", grade required to sign: " 
	<< representation.getSignGrade() << ", is form signed (0 FALSE, 1 TRUE) " 
	<< representation.getIsSigned());
}

void Form::beSigned(Bureaucrat &obj)
{
	if(obj.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade too Low");
}
