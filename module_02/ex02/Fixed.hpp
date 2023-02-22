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
	static const Fixed &min(const Fixed &i, const Fixed &j);
	static const Fixed &max(const Fixed &i, const Fixed &j);
	static Fixed &min(Fixed &i,Fixed &j);
	static Fixed &max(Fixed &i,Fixed &j);

	// below to do
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);
	Fixed& operator++(); //pre
	Fixed operator++(int);
	Fixed& operator--(); //pre
	Fixed operator--(int);

	bool operator>(const Fixed &obj);
	bool operator<(const Fixed &obj);
	bool operator>=(const Fixed &obj);
	bool operator<=(const Fixed &obj);
	bool operator!=(const Fixed &obj);
	bool operator==(const Fixed &obj);

  private:
	int fixed;
	static const int fract = 8;
};

std::ostream & operator<<(std::ostream &stream, const Fixed &representation);

#endif