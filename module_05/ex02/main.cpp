#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	std::cout << "ShrubberyCreationForm:" << std::endl << std::endl;
	try
	{
		Bureaucrat bur("FirstShrubbery", 20);
		ShrubberyCreationForm form1("Shrubbery");
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur("SecShrubbery", 20);
		ShrubberyCreationForm form1("randoom");
		bur.signForm(form1);
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur("ThirdShrubbery", 150);
		ShrubberyCreationForm form1("asd");
		bur.signForm(form1);
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "RobotomyRequestForm" << std::endl << std::endl;

	try
	{
		Bureaucrat bur("FirstRobotmy", 20);
		RobotomyRequestForm form1("Robotmy");
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur("SecRobotmy", 20);
		RobotomyRequestForm form1("randoom");
		bur.signForm(form1);
		form1.execute(bur);
		form1.execute(bur);
		form1.execute(bur);
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur("ThirdRobotmy", 150);
		RobotomyRequestForm form1("asd");
		bur.signForm(form1);
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "PresidentialPardonForm" << std::endl << std::endl;

	try
	{
		Bureaucrat bur("FirstPresidental", 20);
		PresidentialPardonForm form1("Presidental");
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur("SecPresidental", 4);
		PresidentialPardonForm form1("randoom");
		bur.signForm(form1);
		form1.execute(bur);
		form1.execute(bur);
		form1.execute(bur);
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur("ThirdPresidental", 150);
		PresidentialPardonForm form1("asd");
		bur.signForm(form1);
		form1.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}