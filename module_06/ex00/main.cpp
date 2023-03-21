#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Wrong amount of arguments" << std::endl;
        return 0;
    }
    ScalarConverter obj;
    obj.convert(static_cast<std::string>(argv[1]));
}