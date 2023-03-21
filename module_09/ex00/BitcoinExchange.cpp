#include "BitcoinExchange.hpp"

std::deque<t_date> dataToStruct(std::deque<std::string> data)
{
	std::deque<t_date> ret;
	for(unsigned long i = 0; i < data.size(); i++)
	{
		if(!isValidDate(data[i]))
			continue;
		ret.push_back(getDateStruc(data[i]));
	}
	return ret;
}


t_date getDateStruc(std::string line)
{
	t_date ret;
	ret.year = line;
	ret.year.resize(4);
	ret.month = "";
	ret.month += line[5];
	ret.month += line[6];
	ret.day = "";
	ret.day += line[8];
	ret.day += line[9];
	ret.date = line;
	return ret;
}

void calcBtc(std::string line, float btcPrice)
{
	std::string dateSep = "0000-00-00 | ";
	float userValue = atof(line.c_str() + dateSep.length());
	line.resize(10);
	std::cout << line << " => " << userValue << " = " << userValue * btcPrice << std::endl;
}

float getBtcPrice(std::deque<t_date> dataStruc, std::string line)
{
	if(!allChecks(line))
		return -1;
	t_date inputDate = getDateStruc(line);
	if(inputDate.year < dataStruc[0].year || (inputDate.year == dataStruc[0].year && inputDate.month < dataStruc[0].month) || 
		(inputDate.year == dataStruc[0].year && inputDate.month == dataStruc[0].month && inputDate.day < dataStruc[0].day))
	{
		line.resize(10);
		std::cout << "Error: date " << line << " too low" << std::endl;
		return -1;
	}

	std::string date;
	for(unsigned long i = 0; i < dataStruc.size(); i++)
	{
		if(dataStruc[i].year < inputDate.year)
		{
			date = dataStruc[i].date;
			continue;
		}
		if(dataStruc[i].year == inputDate.year && dataStruc[i].month < inputDate.month)
		{
			date = dataStruc[i].date;
			continue;
		}
		if(dataStruc[i].year == inputDate.year && dataStruc[i].month == inputDate.month 
			&& dataStruc[i].day <= inputDate.day)
		{
			date = dataStruc[i].date;
			continue;
		}
	}
	std::string dateLenTilVal = "0000-00-00,";
	return(atof(date.c_str() + dateLenTilVal.length()));
}

bool allChecks(std::string line)
{
	if(isValidDate(line) && isValidSeperator(line) && isValidValue(line)
		&& isValidValueSize(line))
		return true;
	return false;
}

bool isValidDate(std::string line)
{
	std::string validDate = "0000-00-00";
	int validLen = validDate.length();
	for(int i = 0; i < validLen; i++) 
	{
		if((i == 4 || i == 7) && line[i] == '-')
			continue;
		else if(isdigit(line[i]))
			continue;
		return false;
	}
	return true;
}

bool isValidSeperator(std::string line)
{
	std::string seperator = " | ";
	if(line.find(seperator) == std::string::npos)
		return(errorMsg(line));
	return true;
}

bool isValidValue(std::string line)
{
	std::string shortestLine = "0000-00-00 | 1";
	unsigned long i = shortestLine.length() - 1;
	int dotCount = 0;
	if(line.length() < shortestLine.length())
		return(errorMsg(line));
	if(line[i] == '+' || line[i] == '-')
		i++;
	if(line[i] == '\0')
		return(errorMsg(line));
	for(; i < line.length(); i++)
	{
		if(line[i] == '.')
			dotCount++;
		else if(!isdigit(line[i]))
			return false;
		if(dotCount > 1)
			return(errorMsg(line));
	}
	return true;
}

bool isValidValueSize(std::string line)
{
	std::string longestLine = "2011-01-09 | +1000";
	std::string dateSep = "0000-00-00 | ";
	if(line.length() > longestLine.length() || atof(line.c_str() + dateSep.length()) > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	if(atof(line.c_str() + dateSep.length()) < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}

std::deque<std::string> fileToDeque(std::string fileName)
{
	std::deque<std::string> fileDeque;
	std::fstream file(fileName.c_str());
	if(file.fail())
	{
		std::cout << "Error: couldn't open " << fileName << std::endl;
		return fileDeque;
	}
	std::string s;
	while(file)
	{
		std::getline(file, s);
		if(s[0] == '\n')
			continue;
		fileDeque.push_back(s);
	}
	if(fileDeque.empty())
		std::cout << "Error: file was empty" << std::endl;
	return fileDeque;
}

bool errorMsg(std::string line)
{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
}

// // Constructors
// BitcoinExchange::BitcoinExchange()
// {
// }

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
// {
// 	(void) copy;
// }


// // Destructor
// BitcoinExchange::~BitcoinExchange()
// {
// }


// // Operators
// BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
// {
// 	(void) assign;
// 	return *this;
// }

	// int i = 0;
	// 	while(dataStruc[i].year < inputDate.year && i)
	// 	{
	// 		line = dataStruc[i].date;
	// 		i++;
	// 	}
	// 	while(dataStruc[i].month < inputDate.month)
	// 	{
	// 		line = dataStruc[i].date;
	// 		i++;
	// 	}
	// 	while(dataStruc[i].day < inputDate.day)
	// 	{
	// 		line = dataStruc[i].date;
	// 		i++;
	// 	}