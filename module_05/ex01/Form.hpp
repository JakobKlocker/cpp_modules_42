#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class Form
{
  public:
	// Constructors
	Form();
	Form(const Form &copy);
	Form(std::string name);
	Form(std::string name, int signGrade);
	Form(std::string name, int signGrade, int exeGrade);

	// Destructor
	virtual ~Form();

	// Operators
	Form &operator=(const Form &assign);

	//functions
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExeGrade() const;
	std::string getName() const;
	void beSigned(Bureaucrat &obj);


	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
  private:
	const std::string name;
	const int 	signGrade;
	const int 	exeGrade;
	bool isSigned;

};
std::ostream &operator<<(std::ostream &stream,
		const Form &representation);

#endif