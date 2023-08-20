#include "Circle.h"



Circle::Circle()
    :point(0.0, 0.0), radius(0.0)
{

}

Circle::Circle(const std::string& name, const Point2d& point, double radius)
    :Entity(name), point(point), radius(radius)
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

void Circle::setPoint(const Point2d& point)
{
    this->point = point;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}

int Circle::getType() const
{
    return type;
}
