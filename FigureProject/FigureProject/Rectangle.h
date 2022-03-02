#ifndef _RECTANGLE_H
#define _RECTANGLE_H


#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
private:
	 int id;
	 std::string	name;
	 Point2d point;
	 double length;
	 double width;
	 
public:
	Rectangle();
	Rectangle(int id, std::string& name, Point2d& point, double length, double width);

	static const int type = 2;

	void change() override;
	

	void read(DataProvider& file) override;

	void write(DataProvider& file) override;

	void print() override;

	int getType() override;

	int getId();
	std::string getName();
	Point2d getPoint();
	double getLength();
	double getWidth();
	
	void setId(int id);
	void setName(std::string name);
	void setPoint(Point2d& point);
	void setLength(double lenght);
	void setWidth(double width);
	

};
#endif // !_RECTANGLE_H