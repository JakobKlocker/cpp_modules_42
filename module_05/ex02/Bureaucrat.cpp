#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat()
{
	//std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name)
	: name(name)
{
	//std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	//std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	//this->name = assign.name;
	this->grade = assign.grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

void Bureaucrat::incGrade()
{
	if(this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decGrade()
{
	if(this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &representation)
{
	return (stream << representation.getName() << ", bureaucrat grade: " << representation.getGrade());
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too Low");
}

void Bureaucrat::signForm(AForm &obj)
{
	try{
		obj.beSigned(*this);
		std::cout << this->getName() << " signed " << obj.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e){
		std::cout << this->getName() << " couldn't sign " << obj.getName() << " becuase " << e.what() <<  std::endl;
	}
}
