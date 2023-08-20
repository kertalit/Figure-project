#include "Rectangle.h"


Rectangle::Rectangle()
    :point(0.0, 0.0), length(0.0), width(0.0)
{

}

Rectangle::Rectangle(const Point2d& point, double length, double width)
    :point(point), length(length), width(width)
{

}

void Rectangle::readFrom(DataProvider& provider)
{
    Entity::readFrom(provider);
    point = provider.rdPoint2d();
    length = provider.rdDouble();
    width = provider.rdDouble();
}

void Rectangle::writeTo(DataProvider& provider) const
{
    Entity::writeTo(provider);
    provider.writePoint2d(point);
    provider.writeDouble(length);
    provider.writeDouble(width);
}

void Rectangle::setPoint(const Point2d& point)
{
    this->point = point;
}
void Rectangle::setLength(double length)
{
    this->length = length;
}
void Rectangle::setWidth(double width)
{
    this->width = width;
}

int Rectangle::getType() const
{
    return type;
}
