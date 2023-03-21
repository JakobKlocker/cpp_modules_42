#include "Span.hpp"

Span::Span(unsigned int n)
	: maxInts(n)
{
	std::cout << "Span : Default Constructor Called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span : Destructor Called" << std::endl;
}

Span::Span(Span const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		this->span = obj.span;
		this->maxInts = obj.maxInts;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->span.size() >= this->maxInts)
		throw Span::SpanFull();
	span.push_back(n);
}

void	Span::addNumberRange(std::vector<int>::iterator begin,
		std::vector<int>::iterator end)
{
	for(; begin != end; begin++)
	{
		this->addNumber(*begin);
	}
}

const char *Span::SpanFull::what() const throw()
{
	return ("Span is full");
}

const char *Span::SpanNotFound::what() const throw()
{
	return ("Span not found");
}

 int Span::shortestSpan()
{
	int	ret;

	if (this->span.size() <= 1)
		throw Span::SpanNotFound();
	std::vector<int> cpy = this->span;
	std::sort(cpy.begin(), cpy.end());
	ret = cpy[1] - cpy[0];
	for (unsigned long i = 0; i < cpy.size() - 1; i++)
	{
		if (cpy[i + 1] - cpy[i] < ret)
			ret = cpy[i + 1] - cpy[i];
	}
	return (ret);
}
int Span::longestSpan()
{
	if (this->span.size() <= 1)
		throw Span::SpanNotFound();
	std::vector<int> cpy = this->span;
	std::sort(cpy.begin(), cpy.end());
	return(cpy[cpy.size() - 1] - cpy[0]);
}
