#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "ADD - Adds a new Contact\n";
    std::cout << "SEARCH - Displays a specific Contact\n";
    std::cout << "EXIT - Exits the program\n";
}

void PhoneBook::search(PhoneBook book)
{
    int i;

    i = 0;
    while(i < 8)
    {
        book.contacts[i].print_contact(i);
        i++;
    }
}
