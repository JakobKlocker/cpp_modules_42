#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	Fixed::fixed = 0;
	//std::cout << "Default Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	this->fixed = copy.getRawBits();
	//std::cout << "Copy Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const int newInt)
{
	this->fixed = newInt * (1 << Fixed::fract);
	//std::cout << "Int Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const float newFloat)
{
	this->fixed = roundf(newFloat * (1 << Fixed::fract));
	//std::cout << "Float Constructor called of Fixed" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	//std::cout << "Destructor called of Fixed" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&assign != this)
		this->fixed = assign.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &representation)
{
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
	//std::cout << "setRawBits member function called" << std::endl;
	Fixed::fixed = raw;
}

float Fixed::toFloat() const
{
	return (Fixed::fixed / (float)(1 << Fixed::fract));
}

int Fixed::toInt(void) const
{
	return (Fixed::fixed >> Fixed::fract);
}

Fixed &Fixed::min(Fixed &i, Fixed &j)
{
	if (i.getRawBits() < j.getRawBits())
		return (i);
	return (j);
}

const Fixed &Fixed::min(const Fixed &i, const Fixed &j)
{
	if (i.getRawBits() < j.getRawBits())
		return (i);
	return (j);
}

Fixed &Fixed::max(Fixed &i, Fixed &j)
{
	if (i.getRawBits() > j.getRawBits())
		return (i);
	return (j);
}

const Fixed &Fixed::max(const Fixed &i, const Fixed &j)
{
	if (i.getRawBits() > j.getRawBits())
		return (i);
	return (j);
}

//arithmetic operators
Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed ret(*this);
	ret.setRawBits(this->fixed - obj.fixed);
	return (ret);
}

Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed ret(*this);
	ret.setRawBits(this->fixed + obj.fixed);
	return (ret);
}

Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed ret(this->toFloat() * obj.toFloat());
	return (ret);
}

Fixed Fixed::operator/(const Fixed &obj)
{
	Fixed ret(this->toFloat() / obj.toFloat());
	return (ret);
}

//compare operators
bool Fixed::operator>(const Fixed &obj)
{
	return (this->fixed > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj)
{
	return (this->fixed < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj)
{
	return (this->fixed >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj)
{
	return (this->fixed <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj)
{
	return (this->fixed == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj)
{
	return (this->fixed != obj.getRawBits());
}

Fixed &Fixed::operator++()
{
	this->fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{	// static Fixed &min(Fixed &i,Fixed &j);
	// static Fixed &max(Fixed &i,Fixed &j);

	Fixed ret(*this);
	this->fixed++;
	return ret;
}

Fixed &Fixed::operator--()
{
	this->fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	this->fixed--;
	return ret;
}
