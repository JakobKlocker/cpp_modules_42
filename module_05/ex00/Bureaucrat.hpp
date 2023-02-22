#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
  public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);

	// Destructor
	virtual ~Bureaucrat();

	// Operators
	Bureaucrat &operator=(const Bureaucrat &assign);

	//functions
	std::string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
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
	int grade;
};
std::ostream &operator<<(std::ostream &stream,
		const Bureaucrat &representation);

#endif