#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class AForm
{
  public:
	// Constructors
	AForm();
	AForm(const AForm &copy);
	AForm(std::string name);
	AForm(std::string name, int signGrade);
	AForm(std::string name, int signGrade, int exeGrade);

	// Destructor
	virtual ~AForm();

	// Operators
	AForm &operator=(const AForm &assign);

	//functions get
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExeGrade() const;
	std::string getName() const;

	// functions set
	void	setIsSigned(bool Signed);
	void beSigned(Bureaucrat &obj);
	virtual void execute(Bureaucrat const & executor) const  = 0;

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
	class NotSignedException : public std::exception
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
		const AForm &representation);

#endif