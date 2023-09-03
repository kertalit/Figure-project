#include "Rectangle.h"


Rectangle::Rectangle()
    :point(0.0, 0.0), length(0.0), width(0.0)
{

}

Rectangle::Rectangle(const std::string& name, const Point2d& point, double length, double width)
    :Entity(name), point(point), length(length), width(width)
{
    calculateSegments();
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

void Rectangle::Draw(Draw::ptr draw) const
{
    draw.makeCurrent(Style style);
    draw.polyline()
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

void Rectangle::calculateSegments()
{
    std::vector<Point2d> polylineData;

    polylineData.push_back(point);
    polylineData.push_back(Point2d(point.x, point.y + length));
    polylineData.push_back(Point2d(point.x + width, point.y));
    polylineData.push_back(Point2d(point.x + width, point.y + length));

    segments.setPoints(polylineData);
}

int Rectangle::getType() const
{
    return type;
}
