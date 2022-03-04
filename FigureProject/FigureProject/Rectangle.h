#ifndef _RECTANGLE_H
#define _RECTANGLE_H


#include "Figure.h"

class Rectangle : public Figure
{
private:

	 Point2d point;
	 double length;
	 double width;
	 
public:
	Rectangle();
	Rectangle(Point2d& point, double length, double width);

	static const int type = 2;

	void change() override;
	

	void read(DataProvider& file) override;

	void write(DataProvider& file) override;

	void print() override;

	int getType() override;

	Point2d getPoint();
	double getLength();
	double getWidth();
	
	void setPoint(Point2d& point);
	void setLength(double lenght);
	void setWidth(double width);
	

};
#endif // !_RECTANGLE_H