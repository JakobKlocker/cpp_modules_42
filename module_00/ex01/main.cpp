#include "PhoneBook.hpp"
#include "main.hpp"

void    add(PhoneBook &book)
{
    static int i = 0;
    if (i > 7)
        i = 0;
    book.contacts[i].create();
    i++;
}

void    search(PhoneBook &book)
{
    int input;
    book.search(book);
    std::cout << "Enter index of Contact\n";
    std::cin >> input;
    if(input > 7 || input < 0)
    {
        std::cout << "Wrong Index, Re-Enter SEARCH\n";
        return;
    }
    book.contacts[input].print_contact_infos();
}

int main()
{
    int i;
    PhoneBook book;
    std::string input;

    i = 0;
    while(1)
    {
        std::cin >> input;
        if (input == "EXIT")
            return (0);
        else if (input == "ADD")
            add(book);
        else if (input == "SEARCH")
            search(book);
        else
            std::cout << "Invalid Input! Re-enter.\n";
        usleep(10);
    }
    return (0);
}
