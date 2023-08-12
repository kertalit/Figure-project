#include "Rectangle.h"


Rectangle::Rectangle()
    :point(0.0, 0.0), length(0.0), width(0.0)
{

}

Rectangle::Rectangle(const Point2d& point, double length, double width)
    :point(point), length(length), width(width)
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::read(DataProvider& provider)
{
    Figure::read(provider);
    point = provider.rdPoint2d();
    length = provider.rdDouble();
    width = provider.rdDouble();
}

void Rectangle::write(DataProvider& provider) const
{
    Figure::write(provider);
    provider.writePoint2d(point);
    provider.writeDouble(length);
    provider.writeDouble(width);
}

void Rectangle::print() const
{
    Figure::print();
    std::cout << point << std::endl;
    std::cout << length << std::endl;
    std::cout << width << std::endl;
}

int Rectangle::getType() const
{
    return type;
}

Point2d Rectangle::getPoint() const
{
    return point;
}

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setPoint(const Point2d& point)
{
    this->point = point;
}
void Rectangle::setLength(double lenght)
{
    this->length = lenght;
}
void Rectangle::setWidth(double width)
{
    this->width = width;
}