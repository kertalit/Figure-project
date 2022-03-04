#ifndef _POINT2D_H
#define _POINT2D_H

#include <iostream>
#include <fstream>
#include <ostream>

class Point2d
{
public:
	double x;
	double y;

	Point2d();

	Point2d(double x, double y);

};


std::ostream& operator<<(std::ostream& file, const Point2d& point);
std::istream& operator>> (std::istream& file, Point2d& point);

#endif // !_POINT2D_H