#include "Polilyne.h"



Polilyne::Polilyne()
{
	id = 0;
	name = " ";
	amount_of_points = 0;
	points.push_back(Point2d());
}

Polilyne::Polilyne(int id, std::string	name, int amount_of_points, std::vector<Point2d> points)
{
	this->id = id;
	this->name = name;
	this->amount_of_points = amount_of_points;
	this->points.reserve(amount_of_points);

	for (int i = 0; i < amount_of_points; i++)
	{
		this->points.push_back(points[i]);
	}
}


void Polilyne::read(DataProvider& file)
{
	id = file.rdInt();
	name = file.rdString();
	amount_of_points = file.rdInt();

	points.reserve(amount_of_points);

	for (int i = 0; i < amount_of_points; i++)
	{
		Point2d obj = file.rdPoint2d();
		points.push_back(obj);
	}
}

void Polilyne::write(DataProvider& file)
{
	file.writeInt(getType());
	file.writeString(name);
	file.writeInt(amount_of_points);

	for (int i = 0; i < amount_of_points; i++)
	{
		file.writePoint2d(points[i]);
	}

}

void Polilyne::print()
{
	std::cout << id << std::endl;
	std::cout << name << std::endl;
	std::cout << amount_of_points << std::endl;
	
	for (int i = 0; i < amount_of_points; i++)
	{
		std::cout << points[i] << std::endl;
	}

}

int  Polilyne::getType()
{
	return type;
}
