#include "Polilyne.h"



Polilyne::Polilyne()
{
	id = 0;
	name = " ";
	points;
}

Polilyne::Polilyne(int id, const std::string&	name, const std::vector<Point2d>& points)
{
	this->id = id;
	this->name = name;
	this->points = points;

}

void Polilyne::change()
{
	std::string parametr = "";
	std::cout << "Enter name parametr who you want to change: 'id' 'name' 'points' " << std::endl;

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

	else if (parametr == "points")
	{
		std::cout << "Which pair of point do you want to change? (1,2,3...)" << std::endl;
		int number;

		std::cin>>number;

		std::cout << "Enter new point" << std::endl;
		std::cin >> points[number-1];

		std::cout << "Point changed to " << points[number - 1] << std::endl;
	}

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

int Polilyne::getId()
{
	return id;
}

std::string Polilyne::getName()
{
	return name;
}

std::vector<Point2d> Polilyne::getPoints()
{
	return points;
}

void Polilyne::setId(int id)
{
	this->id = id;
}
void Polilyne::setName(std::string name)
{
	this->name = name;
}
void Polilyne::setPoints(std::vector<Point2d> points)
{
	this->points = points;
}
