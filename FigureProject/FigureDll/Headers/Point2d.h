#ifndef _POINT2D_H
#define _POINT2D_H

#include "Platform.h"
#include <iostream>
#include <fstream>
#include <ostream>

class FIGURE_API Point2d
{
public:
    Point2d();
    Point2d(double x, double y);

    double x;
    double y;
};

FIGURE_API std::ostream& operator<< (std::ostream& stream, const Point2d& point);
FIGURE_API std::istream& operator>> (std::istream& stream, Point2d& point);

#endif // !_POINT2D_H