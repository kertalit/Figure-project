#ifndef _POLILYNE_H
#define _POLILYNE_H

#include "Figure.h"
#include "Point2d.h"
#include <vector>
#include <iostream>


class Polilyne : public Figure
{
private:

	std::vector<Point2d> points;

public:
	Polilyne();
	Polilyne(const std::vector<Point2d>& points);

	static const int type = 3;

	void change() override;

	void read(DataProvider& file) override;

	void write(DataProvider& file) override;

	void print() override;
	
	int  getType() override;


	std::vector<Point2d> getPoints();

	void setPoint(const Point2d& point, int number);
	


};

#endif // !_POLILYNE_H