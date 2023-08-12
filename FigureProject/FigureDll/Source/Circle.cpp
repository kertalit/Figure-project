#include "Circle.h"



Circle::Circle()
    :point(0.0, 0.0), radius(0.0)
{

}
Circle::Circle(const Point2d& point, double radius)
    :point(point), radius(radius)
{

}

Circle::~Circle()
{

}

void Circle::read(DataProvider& provider)
{
    Figure::read(provider);
    point = provider.rdPoint2d();
    radius = provider.rdDouble();
}

void Circle::write(DataProvider& provider) const
{
    Figure::write(provider);
    provider.writePoint2d(point);
    provider.writeDouble(radius);
}

void Circle::print() const
{
    Figure::print();
    std::cout << point << std::endl;
    std::cout << radius << std::endl;
}

int Circle::getType() const
{
    return type;
}

Point2d Circle::getPoint() const
{
    return point;
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::setPoint(const Point2d& point)
{
    this->point = point;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}