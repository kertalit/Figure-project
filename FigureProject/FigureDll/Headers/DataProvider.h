#ifndef _FILEDATAPROVIDER_H
#define _FILEDATAPROVIDER_H

#include "Platform.h"
#include "Point2d.h"
#include <ostream>
#include <string>
#include <fstream>


class FIGURE_API DataProvider
{
public:
 virtual int rdInt() = 0;
 virtual std::string rdString() = 0;
 virtual Point2d rdPoint2d() = 0;
 virtual double rdDouble() = 0;

 virtual ~DataProvider();


 virtual void writeInt(const int number) = 0;
 virtual void writePoint2d(const Point2d& point) = 0;
 virtual void writeString(const std::string& line) = 0;
 virtual void writeDouble(const double number) = 0;

 virtual void printPoint2d(const Point2d& point) = 0;
};

#endif // !_FILEDATAPROVIDER_H