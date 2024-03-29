#include "Circle.h"



Circle::Circle()
    :point(0.0, 0.0), radius(0.0)
{

}
Circle::Circle(const Point2d& point, double radius)
    :point(point), radius(radius)
{

}

void Circle::readFrom(DataProvider& provider)
{
    Entity::readFrom(provider);
    point = provider.rdPoint2d();
    radius = provider.rdDouble();
}

void Circle::writeTo(DataProvider& provider) const
{
    Entity::writeTo(provider);
    provider.writePoint2d(point);
    provider.writeDouble(radius);
}

void Circle::toPlan(Plan& plan) const
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