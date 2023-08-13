#include "Circle.h"



Circle::Circle()
    :point(0.0, 0.0), radius(0.0)
{

}
Circle::Circle(const Point2d& point, double radius)
    :point(point), radius(radius)
{

}

void Circle::readInternal(DataProvider& provider)
{
    point = provider.rdPoint2d();
    radius = provider.rdDouble();
}

void Circle::writeInternal(DataProvider& provider) const
{
    provider.writePoint2d(point);
    provider.writeDouble(radius);
}

void Circle::print() const
{
    Entity::print();
    std::cout << point << std::endl;
    std::cout << radius << std::endl;
}

void Circle::ToPlan(Plan& plan) const
{
}

int Circle::getType() const
{
    return type;
}

void Circle::setPoint(const Point2d& point)
{
    this->point = point;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}