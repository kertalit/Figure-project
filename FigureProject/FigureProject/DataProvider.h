#ifndef _DATAPROVIDER_H
#define _DATAPROVIDER_H


#pragma once
#include "Point2d.h"
#include <ostream>
#include <string>
#include <fstream>

class DataProvider
{
	
private:
	std::ifstream inFile;
	std::ofstream outFile;

public:

	

	DataProvider(std::ifstream& file, const std::string& path);

	DataProvider(std::ofstream& file, const std::string& path);

	~DataProvider();
	
	
	int rdInt();

	std::string rdString();

	Point2d rdPoint2d();

	double rdDouble();

	void writeInt(const int number);

	void writePoint2d(const Point2d& point);

	void writeString(const std::string line);

	void writeDouble(const double number);

	void printPoint2d(const Point2d &point);
	
	

};

#endif // !_DATAPROVIDER_H