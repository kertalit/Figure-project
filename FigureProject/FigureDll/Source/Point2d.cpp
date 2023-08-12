#include "Point2d.h"


Point2d::Point2d()
    :x(0.0), y(0.0)
{

}

Point2d::Point2d(double x, double y)
    :x(x), y(y)
{

}

std::ostream& operator<<(std::ostream& stream, const Point2d& point)
{
    stream << point.x << std::endl;
    stream << point.y;

    return stream;
}

std::istream& operator>> (std::istream& stream, Point2d& point)
{
    stream >> point.x >> point.y;

    return stream;
}