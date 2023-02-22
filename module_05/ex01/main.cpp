#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main(void)
{
	try{
		Bureaucrat bur("Dan", 20);
		Form	form("Eval", 9);
		bur.signForm(form);

		std::cout << bur << std::endl;
		std::cout << form << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		try{
		Bureaucrat bur("Dan2", 9);
		Form	form("Eval2", 20);
		bur.signForm(form);

		std::cout << bur << std::endl;
		std::cout << form << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}