#include "Contact.hpp"

void Contact::create()
{
	std::string input;
	do
	{
		std::cout << "Enter First Name:\n";
		std::cin >> input;
	} while (input == "");
	Contact::first_name = input;
	do
	{
		std::cout << "Enter Last Name:\n";
		std::cin >> input;
	} while (input == "");
	Contact::last_name = input;
	do
	{
		std::cout << "Enter Nickname:\n";
		std::cin >> input;
	} while (input == "");
	Contact::nickname = input;
	do
	{
		std::cout << "Phone Number:\n";
		std::cin >> input;
	} while (input == "");
	Contact::phone_nbr = input;
	do
	{
		std::cout << "Darkest Secret:\n";
		std::cin >> input;
	} while (input == "");
	Contact::secret = input;
}

void Contact::print_contact(int i)
{
	if (Contact::first_name == "")
		return;
	std::cout.width(10);
	std::cout << std::right << i << "|";
	std::cout.width(10);
	std::cout << std::right << truncate(Contact::first_name) << "|";
	std::cout.width(10);
	std::cout << std::right << truncate(Contact::last_name) << "|";
	std::cout.width(10);
	std::cout << std::right << truncate(Contact::nickname) << "\n";
}

void Contact::print_contact_infos()
{
	if(Contact::first_name == "")
	{
		std::cout << "Wrong Index, Re-Enter SEARCH\n";
		return;
	}
    std::cout << Contact::first_name << "\n";
    std::cout << Contact::last_name << "\n";
    std::cout << Contact::phone_nbr << "\n";
    std::cout << Contact::secret << "\n";
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}
