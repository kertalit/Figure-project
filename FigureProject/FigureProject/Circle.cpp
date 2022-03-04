#include "Circle.h"



Circle::Circle()
	: point(0.0,0.0), radius(0.0)
{

}
Circle::Circle(const Point2d& point, double radius)
	: point(0.0, 0.0), radius(0.0)
{

}

void Circle::change()
{
	std::string parametr = "";
	std::cout << "Enter name parametr who you want to change: 'id' 'name' 'point' 'radius' " << std::endl;
	
	std::cin >> parametr;

	if (parametr == "id")
	{
		int newId;
		std::cout << "Enter new id" << std::endl;
		std::cin >> newId;
		setId(newId);

		std::cout << "Id changed to " << newId << std::endl;
	}

	else if (parametr == "name")
	{
		std::string newName;
		std::cout << "Enter new name" << std::endl;
		std::cin >> newName;
		setName(newName);

		std::cout << "Name changed to " << newName << std::endl;
	}

	else if (parametr == "point")
	{
		Point2d newPoint;
		std::cout << "Enter new point" << std::endl;
		std::cin >> newPoint;
		setPoint(newPoint);

		std::cout << "Point changed to " << newPoint << std::endl;
	}

	else if (parametr == "radius")
	{
		double newRadius;
		std::cout << "Enter new radius" << std::endl;
		std::cin >> newRadius;
		setRadius(newRadius);

		std::cout << "Radius changed to " << newRadius << std::endl;
	}
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


void Circle::setPoint(Point2d point)
{
	this->point = point;
}
void Circle::setRadius(double radius)
{
	this->radius = radius;
}
