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
	Circle(int id, const std::string&	name, const Point2d& point, double radius);

	static const int type = 1;



	void read(DataProvider& file) override;

	void write(DataProvider& file) override;

	void print() override;

	int getType() override;

	

};

#endif // !_CIRCLE_H
