#include "Fixed.hpp"


// Constructors
Fixed::Fixed()
{
	Fixed::fixed = 0;
	std::cout << "Default Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	this->fixed = copy.getRawBits();
	std::cout << "Copy Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const int newInt)
{
	this->fixed = newInt * (1 << Fixed::fract);
	std::cout << "Int Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const float newFloat)
{
	this->fixed = roundf(newFloat * (1 << Fixed::fract));
	std::cout << "Float Constructor called of Fixed" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called of Fixed" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&assign != this)
		this->fixed = assign.getRawBits();
	return (*this);
}

std::ostream& operator<< (std::ostream& stream, const Fixed& representation)
{
	//return (stream << representation.getRawBits() / (1 << 8) << "." << (representation.getRawBits() * (1 << 8)) << std::endl);
	return (stream << representation.toFloat());
}


// Functions
int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::fixed = raw;
}

float Fixed::toFloat() const
{
	return (Fixed::fixed / (float)(1 << Fixed::fract));
}

// Why do I not lose the sign bit here ?!
int Fixed::toInt( void ) const
{
	return(Fixed::fixed >> Fixed::fract);
	//return(roundf(Fixed::fixed / (1 << Fixed::fract)));
	// for(int i = 0; i < Fixed::fract, i++)
	// {
	// 	ret = ret >>;
	// }
	// std::shift_left() Fixed::fixed
}