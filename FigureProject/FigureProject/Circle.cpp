#include "Circle.h"



Circle::Circle()
	:id(0), name(" "), point(0.0,0.0), radius(0.0)
{

}
Circle::Circle(int id, const std::string& name, const Point2d& point, double radius)
	:id(0), name(" "), point(0.0, 0.0), radius(0.0)
{

}


void Circle::read(DataProvider& file) 
	{
		id = file.rdInt();
		name = file.rdString();
		point = file.rdPoint2d();
		radius = file.rdDouble();
	}

void Circle::write(DataProvider& file)
	{
		file.writeInt(getType());
		file.writeInt (id);
		file.writeString(name);
		file.writePoint2d(point);
		file.writeDouble(radius);
	}

void Circle::print()
{
	std::cout << id << std::endl;
	std::cout << name << std::endl;
	std::cout << point << std::endl;
	std::cout << radius << std::endl;
}

int  Circle::getType() 
	{
		return type;
	}
