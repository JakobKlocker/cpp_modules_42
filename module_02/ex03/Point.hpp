#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <string>

class Point
{
  public:
	// Constructors
	Point();
	Point(const Fixed _x, const Fixed _y);
	Point(const Point &copy);

	// Destructor
	~Point();

	// Operators
	void operator=(const Point &assign);
	bool bsp(Point const a, Point const b, Point const c, Point const point);
	Fixed sign(const Point &p1, const Point &p2, const Point &p3);
	Fixed getX() const;
	Fixed getY() const;

  private:
	Fixed const x;
	Fixed const y;
};

#endif