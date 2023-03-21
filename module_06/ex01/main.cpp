#include "Serializer.hpp"

int main()
{
    Data dat;
    Data *pDat = &dat;
    Serializer conv;

    std::cout << "Original pDat: " << pDat << std::endl;
    std::cout << "After Conv (should be same addr) " <<  conv.deserialize(conv.serialize(pDat)) << std::endl;
}