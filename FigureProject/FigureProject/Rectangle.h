#ifndef _RECTANGLE_H
#define _RECTANGLE_H


#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
	int id;
	std::string	name;
	Point2d point;
	double length;
	double width;
public:

	Rectangle(int id, std::string name, Point2d point, double length, double width);
	Rectangle();

	void read(std::ifstream& file) override;

	void print() override;

	void write(std::ofstream& file) override;

	int getType() override;

	DataProvider dataprovider;
};
#endif // !_RECTANGLE_H