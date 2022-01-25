#ifndef _DATAPROVIDER_H
#define _DATAPROVIDER_H


#pragma once
#include "Point2d.h"
#include <ostream>
#include <string>
#include <fstream>

class DataProvider
{
	
public:
	int rdInt(std::ifstream& file);

	std::string rdString(std::ifstream& file);

	Point2d rdPoint2d(std::ifstream& file);

	double rdDouble(std::ifstream& file);

	void writeInt(std::ofstream& file, int number);

	void writePoint2d(std::ofstream& oFile, Point2d& point);

	void writeString(std::ofstream& file, std::string line);

	void writeDouble(std::ofstream& file, double number);

	void printPoint2d(Point2d point);
	
	

};

#endif // !_DATAPROVIDER_H