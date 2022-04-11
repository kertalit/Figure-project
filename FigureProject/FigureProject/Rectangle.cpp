#include "Rectangle.h"


Rectangle::Rectangle()
	: point(0.0, 0.0), length(0.0), width(0.0)
{

}

Rectangle::Rectangle(const Point2d& point, double length, double width)
	: point(0.0, 0.0), length(0.0), width(0.0)
{

}

void Rectangle::read(DataProvider& file)
	{
		Figure::read(file);
		point = file.rdPoint2d();
		length = file.rdDouble();
		width = file.rdDouble();
	}


void Rectangle::write(DataProvider& file)
	{
		file.writeInt(getType());
		Figure::write(file);
		file.writePoint2d(point);
		file.writeDouble(length);
		file.writeDouble(width);
	}

void Rectangle::print()
{
	Figure::print();
	std::cout << point << std::endl;
	std::cout << length << std::endl;
	std::cout << width << std::endl;
}

int Rectangle::getType()
	{
		return type;
	}


Point2d Rectangle::getPoint()
{
	return point;
}

double Rectangle::getLength()
{
	return length;
}

double Rectangle::getWidth()
{
	return width;
}

void Rectangle::setPoint(const Point2d& point)
{
	this->point = point;
}
void Rectangle::setLength(double lenght)
{
	this->length = lenght;
}
void Rectangle::setWidth(double width)
{
	this->width = width;
}