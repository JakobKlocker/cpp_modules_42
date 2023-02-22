#include "Point.hpp"

// Constructors
Point::Point():x(0), y(0)
{
	//std::cout << "\e[0;33mDefault Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const Fixed _x, const Fixed _y):x(_x), y(_y)
{
	//std::cout << "\e[0;33mDefault Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const Point &copy):x(copy.x), y(copy.y)
{
	(void) copy;
	//std::cout << "\e[0;33mCopy Constructor called of Point\e[0m" << std::endl;
}


// Destructor
Point::~Point()
{
	//std::cout << "\e[0;31mDestructor called of Point\e[0m" << std::endl;
}


// Operators
void Point::operator=(const Point &assign)
{
	(void)assign;
	std::cout << "can't copy because of const" << std::endl;
}

Fixed	Point::getX() const
{
	return(this->x);
}

Fixed	Point::getY() const
{
	return(this->y);
}

Fixed Point::sign (const Point &p1,const Point &p2,const Point &p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{	
	Fixed p1(sign(point, a, b));
	Fixed p2(sign(point, b, c));
	Fixed p3 (sign(point, c, a));
	if(p1.getRawBits() == 0 || p2.getRawBits() == 0 || p3.getRawBits() == 0)
		return false;
	bool is_neg = (p1 < 0) || (p2 < 0) || (p3 < 0);
    bool is_pos = (p1 > 0) || (p2 > 0) || (p3 > 0);
	return !(is_neg && is_pos);
}