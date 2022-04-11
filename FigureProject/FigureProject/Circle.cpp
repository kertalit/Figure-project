#include "Circle.h"



Circle::Circle()
	: point(0.0,0.0), radius(0.0)
{

}
Circle::Circle(const Point2d& point, double radius)
	: point(0.0, 0.0), radius(0.0)
{

}

void Circle::read(DataProvider& file)
	{
		Figure::read(file);
		point = file.rdPoint2d();
		radius = file.rdDouble();
	}

void Circle::write(DataProvider& file)
	{
		file.writeInt(getType());
		Figure::write(file);
		file.writePoint2d(point);
		file.writeDouble(radius);
	}

void Circle::print()
{
	Figure::print();
	std::cout << point << std::endl;
	std::cout << radius << std::endl;
}



int  Circle::getType() 
	{
		return type;
	}


Point2d Circle::getPoint()
{
	return point;
}

double Circle::getRadius()
{
	return radius;
}


void Circle::setPoint(const Point2d& point)
{
	this->point = point;
}
void Circle::setRadius(double radius)
{
	this->radius = radius;
}
