#include "Rectangle.h"


Rectangle::Rectangle()
	: point(0.0, 0.0), length(0.0), width(0.0)
{

}

Rectangle::Rectangle(Point2d& point, double length, double width)
	: point(0.0, 0.0), length(0.0), width(0.0)
{

}

void Rectangle::change()
{
	std::string parametr = "";
	std::cout << "Enter name parametr who you want to change: 'id' 'name' 'point' 'length' 'width' " << std::endl;

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

	else if (parametr == "length")
	{
		double newLength;
		std::cout << "Enter new length" << std::endl;
		std::cin >> newLength;
		setLength(newLength);

		std::cout << "Length changed to " << newLength << std::endl;
	}

	else if (parametr == "width")
	{
		double newWidth;
		std::cout << "Enter new width" << std::endl;
		std::cin >> newWidth;
		setLength(newWidth);

		std::cout << "Width changed to " << newWidth << std::endl;
	}
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

void Rectangle::setPoint(Point2d& point)
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