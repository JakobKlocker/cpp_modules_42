#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error: wrong arguments." << std::endl;
        return (1);
    }

    std::deque<std::string> userFile = fileToDeque(argv[1]);
    if(userFile.empty())
        return (1);
    std::deque<std::string> dataFile = fileToDeque("data.csv");
    if(dataFile.empty())
        return (1);
    std::deque<t_date> dataStruc = dataToStruct(dataFile);
    float btcPrice = -1;
    for(unsigned long i = 0; i < userFile.size(); i++)
    {
        btcPrice = getBtcPrice(dataStruc, userFile[i]);
        if(btcPrice == -1)
            continue;
        calcBtc(userFile[i], btcPrice);
    }
}