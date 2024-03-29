#include "Polyline.h"



Polyline::Polyline()
{

}

Polyline::Polyline(const std::vector<Point2d>& points)
    :points(points)
{

}

void Polyline::readFrom(DataProvider& provider)
{
    Entity::readFrom(provider);

    int size = provider.rdInt();
    points.reserve(size);

    for (int i = 0; i < size; i++)
    {
        points.push_back(provider.rdPoint2d());
    }
}


void Polyline::writeTo(DataProvider& provider) const
{
    Entity::writeTo(provider);
    provider.writeInt(points.size());

    for (const auto& point : points)
    {
        provider.writePoint2d(point);
    }
}

void Polyline::toPlan(Plan& plan) const
{
}

int  Polyline::getType() const
{
    return type;
}

void Polyline::setPoint(const Point2d& point, size_t number)
{

    if (number >= points.size())
        throw std::exception("Value greater than the number of points");
    else
        points[number] = point;
}