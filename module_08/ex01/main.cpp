#include "Span.hpp"

int	main(void)
{
	Span sp = Span(500);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.addNumber(612312);
	sp.addNumber(12312);
	sp.addNumber(123123);
	sp.addNumber(9123123);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
    std::vector<int> test;
    for(int i= 0; i < 5; i++)
    {
        test.push_back(i);
    }
    Span cpy(10);
    cpy.addNumberRange(test.begin(), test.end());
	std::cout << cpy.shortestSpan() << std::endl;
	std::cout << cpy.longestSpan() << std::endl;
	return (0);
}