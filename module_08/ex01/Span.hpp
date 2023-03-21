#ifndef _Span_HPP_
#define _Span_HPP_
#include <stdlib.h>
# include <vector>
# include <algorithm>
# include <iostream>

class	Span
{
	public	:
		Span (unsigned int n);
		Span (Span const &obj);
		~Span ();
		Span &operator= (const Span &obj);

		void addNumber(int n);
		void addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		class SpanFull : public std::exception
		{
			public:
			    const char* what() const throw();
		};
		class SpanNotFound : public std::exception
		{
			public:
			    const char* what() const throw();
		};
	private	:
		unsigned int maxInts;
		std::vector<int> span;
};

#endif
