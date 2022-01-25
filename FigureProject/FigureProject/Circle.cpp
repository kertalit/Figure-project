#include "Circle.h"


Circle::Circle()
	:id(0),name(" "), point(0.0,0.0), radius(0.0)
{

}
Circle::Circle(int id, std::string	name, Point2d point, double radius)
	:id(0), name(" "), point(0.0, 0.0), radius(0.0)
{

}

void Circle::read(std::ifstream& file) 
	{
		id = dataprovider.rdInt(file);
		name = dataprovider.rdString(file);
		point = dataprovider.rdPoint2d(file);
		radius = dataprovider.rdDouble(file);
	}

	void Circle::print()
	{
		std::cout << id << std::endl;
		std::cout << name << std::endl;
		dataprovider.printPoint2d(point);
		std::cout << radius << std::endl;

	}

	void Circle::write(std::ofstream& file)
	{
		file << getType() << std::endl;
		dataprovider.writeInt (file, id);
		dataprovider.writeString(file, name);
		dataprovider.writePoint2d(file, point);
		dataprovider.writeDouble(file, radius);
	}

	int Circle::getType()
	{
		int type = 1;
		return type;
	}
