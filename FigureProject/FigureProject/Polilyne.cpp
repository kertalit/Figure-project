#include "Polilyne.h"



Polilyne::Polilyne()
{
	id = 0;
	name = " ";
	countPoints = 0;
	points.push_back(Point2d());
}

Polilyne::Polilyne(int id, std::string	name, const std::vector<Point2d>& points)
{
	this->id = id;
	this->name = name;
	this->points = points;

}


void Polilyne::read(DataProvider& file)
{
	id = file.rdInt();
	name = file.rdString();
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
	file.writeString(name);
	file.writeInt(points.size());

	for (int i = 0; i < points.size(); i++)
	{
		file.writePoint2d(points[i]);
	}

}

void Polilyne::print()
{
	std::cout << id << std::endl;
	std::cout << name << std::endl;
	std::cout << countPoints << std::endl;
	
	for (int i = 0; i < countPoints; i++)
	{
		std::cout << points[i] << std::endl;
	}

}

int  Polilyne::getType()
{
	return type;
}
