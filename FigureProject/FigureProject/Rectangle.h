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
	

	void  read(DataProvider& file) override;

	void  write(DataProvider& file) override;

	void  print() override;

	int   getType() override;

};
#endif // !_RECTANGLE_H