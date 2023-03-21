#include "easyfind.hpp"

const char* NotFound::what() const throw()
{
    return ("Not Found, reached exception");
}

int main()
{
    std::vector<int> num;

    for(int i = 0; i < 5; i++)
    {
        num.push_back(i);
    }
    try{
        easyfind(num, 3);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        easyfind(num, 6);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}