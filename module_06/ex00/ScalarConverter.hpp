#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
#include <sstream>
#include <cstdlib>


class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		// Destructor
		void convert(std::string inp);
		~ScalarConverter();
		
		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);
		
		//functions
		void printInt(std::string inp);
		void printFloat(std::string inp);
		void printDouble(std::string inp);

		bool isNanInf(std::string inp);
		void printChar(std::string inp);

	private:
		char c;
		int i;
		float f;
		double d;
};

#endif