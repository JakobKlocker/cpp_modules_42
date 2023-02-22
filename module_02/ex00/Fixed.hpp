#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
  public:
	// Constructors
	Fixed();
	Fixed(const Fixed &copy);

	// Destructor
	~Fixed();

	// Operators
	Fixed &operator=(const Fixed &assign);

	//Functions
	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int fixed;
	static const int fract = 8;
};

#endif