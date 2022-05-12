#ifndef _POLILYNE_H
#define _POLILYNE_H


#include "Platform.h"
#include "Figure.h"
#include "Point2d.h"
#include <vector>
#include <iostream>


class FIGURE_API Polilyne : public Figure
{
private:

	std::vector<Point2d> points;

public:
	Polilyne();
	Polilyne(const std::vector<Point2d>& points);

	static const int type = 3;

	void read(DataProvider& provider) override;

	void write(DataProvider& provider) override;

	void print() override;

	
	int  getType() const override;
	std::vector<Point2d> getPoints() const;

	void setPoint(const Point2d& point, size_t number);
	


};

#endif // !_POLILYNE_H