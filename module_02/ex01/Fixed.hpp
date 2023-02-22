#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
  public:
	// Constructors
	Fixed();
	Fixed(const int newInt);
	Fixed(const float newFloat);
	Fixed(const Fixed &copy);

	// Destructor
	~Fixed();

	// Operators
	Fixed &operator=(const Fixed &assign);
	

	//Functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

  private:
	int fixed;
	static const int fract = 8;
};

std::ostream & operator<<(std::ostream &stream, const Fixed &representation);

#endif