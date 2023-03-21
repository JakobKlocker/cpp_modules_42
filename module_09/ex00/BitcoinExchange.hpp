#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
# include <deque>

typedef struct{
    std::string year;
    std::string month;
    std::string day;
    std::string date;
} t_date;

float getBtcPrice(std::deque<t_date> dataStruc, std::string line);
void calcBtc(std::string line, float btcPrice);
std::deque<std::string> fileToDeque(std::string fileName);
t_date getDateStruc(std::string line);
std::deque<t_date> dataToStruct(std::deque<std::string> data);
bool allChecks(std::string line);
bool isValidDate(std::string line);
bool isValidSeperator(std::string line);
bool isValidValue(std::string line);
bool isValidValueSize(std::string line);
bool errorMsg(std::string line);


// class BitcoinExchange
// {
// 	public:
// 		// Constructors
// 		BitcoinExchange();
// 		BitcoinExchange(const BitcoinExchange &copy);
		
// 		// Destructor
// 		~BitcoinExchange();
		
// 		// Operators
// 		BitcoinExchange & operator=(const BitcoinExchange &assign);
		
// 	private:
		
// };

#endif