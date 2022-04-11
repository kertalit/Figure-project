#include "Polilyne.h"



Polilyne::Polilyne()
{
	points;
}

Polilyne::Polilyne(const std::vector<Point2d>& points)
{
	
	this->points = points;

}

void Polilyne::read(DataProvider& file)
{
	Figure::read(file);
	int size = file.rdInt();

	points.reserve(size);

	for (int i = 0; i < size; i++)
	{
		Point2d obj = file.rdPoint2d();
		points.push_back(obj);
	}
}


void Polilyne::write(DataProvider& file)
{
	file.writeInt(getType());
	Figure::write(file);
	file.writeInt(points.size());

	for (int i = 0; i < points.size(); i++)
	{
		file.writePoint2d(points[i]);
	}

}

void Polilyne::print()
{
	Figure::print();
	std::cout << points.size() << std::endl;
	
	for (int i = 0; i < points.size(); i++)
	{
		std::cout << points[i] << std::endl;
	}

}

int  Polilyne::getType()
{
	return type;
}


std::vector<Point2d> Polilyne::getPoints()
{
	return points;
}


void Polilyne::setPoint(const Point2d& point, int number)
{
	this->points[number - 1] = point;
}
