#include "RPN.hpp"
 
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Wrong amount of Arguments." << std::endl;
        return (1);
    }
    validCheck(argv[1]);
    std::cout << rpnCalc(argv[1]) << std::endl;
}