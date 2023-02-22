#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	Fixed::fixed = 0;
	std::cout << "Default Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called of Fixed" << std::endl;
	*this = copy;
}


// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called of Fixed" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&assign != this)
		this->fixed = assign.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return Fixed::fixed;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::fixed = raw;
}
