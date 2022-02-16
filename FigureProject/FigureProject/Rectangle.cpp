#include "Rectangle.h"


Rectangle::Rectangle()
	: id(0), name(" "), point(0.0, 0.0), length(0.0), width(0.0)
{

}

Rectangle::Rectangle(int id, std::string& name, Point2d& point, double length, double width)
	:id(0), name(""), point(0.0, 0.0), length(0.0), width(0.0)
{

}

void Rectangle::read( DataProvider& file)
	{
		id = file.rdInt();
		name = file.rdString();
		point = file.rdPoint2d();
		length = file.rdDouble();
		width = file.rdDouble();
	}

void Rectangle::write(DataProvider& file)
	{
		file.writeInt(getType());
		file.writeInt(id);
		file.writeString(name);
		file.writePoint2d(point);
		file.writeDouble(length);
		file.writeDouble(width);
	}

void Rectangle::print()
{
	std::cout << id << std::endl;
	std::cout << name << std::endl;
	std::cout << point << std::endl;
	std::cout << length << std::endl;
	std::cout << width << std::endl;
}

int Rectangle::getType()
	{
		return type;
	}