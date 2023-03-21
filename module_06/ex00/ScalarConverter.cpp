#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter(): c(0), i(0), f(0), d(0)
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}


// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	this->c = assign.c;
	this->i = assign.i;
	this->f = assign.f;
	this->d = assign.d;
	return *this;
}

bool ScalarConverter::isNanInf(std::string inp)
{
	if(inp == "+inff" || inp == "+inf" || inp == "-inff" || inp == "-inf" || inp == "nan" || inp == "nanf")
		return true;
	return false;
}

void ScalarConverter::printChar(std::string inp)
{
	if(isNanInf(inp) || this->i > 127 || this->i < 0)
		std::cout << "impossible" << std::endl;
	else if(!isprint(this->c))
		std::cout << "not displayable" << std::endl;
	else
		std::cout << this->c << std::endl;
}

void ScalarConverter::printInt(std::string inp)
{
	if(isNanInf(inp))
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->i << std::endl;
}

void ScalarConverter::printDouble(std::string inp)
{
	if(inp == "+inff" || inp == "+inf")
		std::cout << "+inf" << std::endl;
	else if(inp == "-inff" || inp == "-inf")
		std::cout << "-inf" << std::endl;
	else if(inp == "nan" || inp == "nanf")
		std::cout << "nan" << std::endl;
	else if(this->d - static_cast<int>(d) == 0)
		std::cout << this->d << ".0" << std::endl;
	else
		std::cout << this->d << std::endl;
}

void ScalarConverter::printFloat(std::string inp)
{
	if(inp == "+inff" || inp == "+inf")
		std::cout << "+inff" << std::endl;
	else if(inp == "-inff" || inp == "-inf")
		std::cout << "-inff" << std::endl;
	else if(inp == "nan" || inp == "nanf")
		std::cout << "nanf" << std::endl;
	else if(this->f - static_cast<int>(f) == 0)
		std::cout << this->f << ".0f" << std::endl;
	else
		std::cout << this->f << "f" << std::endl;
}

bool isCorrectInp(std::string inp)
{
	if(inp[0] == '\0')
		return false;
	if(inp == "+inff" || inp ==  "+inf" || inp ==  "-inff" || inp ==  "-inf"
	|| inp ==  "nan" || inp ==  "nanf" )
		return true;
	if(inp.length() == 1)
		return true;
	int i = 0;
	if(inp[0] == '-' || inp[0] == '+')
		i++;
	int dots = 0;
	for(unsigned long j = i; j < inp.length(); j++)
	{
		if(inp[j] == '.')
			dots++;
		if(isdigit(inp[j]) == 0 && inp[j] != '.' && inp[j] != 'f')
		{
			return false;
		}
		if(dots > 1)
			return false;
	}
	return true;
}

bool isFloat(std::string inp)
{
	std::istringstream iss(inp);
	float f;
	iss >> f;
	return iss.eof() && !iss.fail();
}

void ScalarConverter::convert(std::string inp)
{
	if(isCorrectInp(inp) == 0)
	{
		std::cout << "incorrect input, ints, floats, doubles, single ascii chars allowed" << std::endl;
		return;
	}
	if(inp.length() == 1 && isprint(inp[0]) && isalpha(inp[0]))
	{
		this->c = inp[0];
		this->i = static_cast<int>(this->c);
		this->f = static_cast<float>(this->c);
		this->d = static_cast<double>(this->c);
	}
	else
	{

		this->i = atoi(inp.c_str());
		this->c = static_cast<char>(i);
		this->f = std::atof(inp.c_str());
		this->d = std::atof(inp.c_str());
	}
	printChar(inp);
	printInt(inp);
	printFloat(inp);
	printDouble(inp);
}
