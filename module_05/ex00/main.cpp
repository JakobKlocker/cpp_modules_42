#include "Bureaucrat.hpp"
int	main(void)
{
	try
	{
		Bureaucrat a("test", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat b("test", -32);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat c("test", 1);
		c.incGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat d("test", 150);
		d.decGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}