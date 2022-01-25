#ifndef _CIRCLE_H
#define _CIRCLE_H


#pragma once
#include "Figure.h"



class Circle : public Figure
{
private:
	int id;
	std::string	name;
	Point2d point;
	double radius;

public:
	Circle();
	Circle(int id, std::string	name, Point2d point, double radius);

	void read(std::ifstream& file) override;

	void print() override;

	void write(std::ofstream& file) override;

	int getType() override;

	DataProvider dataprovider;

};

#endif // !_CIRCLE_H
