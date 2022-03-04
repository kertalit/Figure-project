#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Figure.h"



class Circle : public Figure
{
private:

	Point2d point;
	double radius;

public:
	Circle();
	Circle(const Point2d& point, double radius);

	static const int type = 1;

	void change() override;

	void read(DataProvider& file) override;
	

	void write(DataProvider& file) override;

	void print() override;

	int getType() override;

	
	Point2d getPoint();
	double getRadius();


	void setPoint(Point2d point);
	void setRadius(double radius);

	

};

#endif // !_CIRCLE_H
