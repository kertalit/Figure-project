#ifndef _POLILYNE_H
#define _POLILYNE_H

#pragma once
#include "Figure.h"
#include "Point2d.h"
#include <vector>
#include <iostream>


class Polilyne : public Figure
{
private:

	int id;
	std::string	name;
	std::vector<Point2d> points;

public:
	Polilyne();
	Polilyne(int id, const std::string&	name, const std::vector<Point2d>& points);

	static const int type = 3;

	void change() override;

	void read(DataProvider& file) override;

	void write(DataProvider& file) override;

	void print() override;
	
	int  getType() override;

	int getId();
	std::string getName();
	std::vector<Point2d> getPoints();

	void setId(int id);
	void setName(std::string name);
	void setPoints(std::vector<Point2d> points);

	


};

#endif // !_POLILYNE_H