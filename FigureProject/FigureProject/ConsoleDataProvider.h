#ifndef _C_DATAPROVIDER_H
#define _C_DATAPROVIDER_H


#include "Point2d.h"
#include <ostream>
#include <string>
#include <fstream>
#include "DataProvider.h"

class ConsoleDataProvider : public DataProvider
{

public:

	ConsoleDataProvider();

	~ConsoleDataProvider();


	int rdInt() override;

	std::string rdString() override;

	Point2d rdPoint2d() override;

	double rdDouble() override;

	void writeInt(const int number) override;

	void writePoint2d(const Point2d& point) override;

	void writeString(const std::string& line) override;

	void writeDouble(const double number) override;

	void printPoint2d(const Point2d& point) override;

};

#endif // !_C_DATAPROVIDER_H