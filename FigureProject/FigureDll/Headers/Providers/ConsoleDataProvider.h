#ifndef _C_DATAPROVIDER_H
#define _C_DATAPROVIDER_H

#include "DataProvider.h"

#include <ostream>
#include <string>
#include <fstream>

class FIGURE_API ConsoleDataProvider : public DataProvider
{
public:
    ~ConsoleDataProvider() override;

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