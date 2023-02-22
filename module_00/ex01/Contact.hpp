#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

std::string truncate(std::string str);
class Contact
{
  public:
	void create();
	void print_contact(int i);
	void print_contact_infos();

  private:
	std::string first_name;
	std::string phone_nbr;
	std::string last_name;
	std::string nickname;
	std::string secret;
};

#endif