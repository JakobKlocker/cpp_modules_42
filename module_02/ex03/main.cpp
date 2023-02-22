#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point p1(0, 0);
    Point p2(0, 1);
    Point p3(1, 0);
    Point point(0.2f, 0.2f);
    if(p1.bsp(p1, p2, p3, point))
        std::cout << "Inside" << std::endl;
    else 
        std::cout << "Outside" << std::endl;
    Point p4(0, 0);
    Point p5(0, 1);
    Point p6(1, 0);
    Point point1(1.0f, 0.0f);
    if(p1.bsp(p4, p5, p6, point1))
        std::cout << "Inside" << std::endl;
    else 
        std::cout << "Outside" << std::endl;
    Point p7(0, 0);
    Point p8(0, 1);
    Point p9(1, 0);
    Point point2(1.1f, 0.0f);
    if(p1.bsp(p7, p8, p9, point2))
        std::cout << "Inside" << std::endl;
    else 
    {
        std::cout << "Outside" << std::endl;
    }
    
	return (0);
}
