#include "Polyline.h"



Polyline::Polyline()
{

}

Polyline::Polyline(const std::vector<Point2d>& points)
    :points(points)
{

}

Polyline::~Polyline()
{

}

void Polyline::read(DataProvider& provider)
{
    Entity::read(provider);
    int size = provider.rdInt();

    points.reserve(size);

    for (int i = 0; i < size; i++)
    {
        points.push_back(provider.rdPoint2d());
    }
}


void Polyline::write(DataProvider& provider) const
{
    Entity::write(provider);
    provider.writeInt(points.size());

    for (const auto& point : points)
    {
        provider.writePoint2d(point);
    }
}

void Polyline::print() const
{
    Entity::print();
    std::cout << points.size() << std::endl;

    for (const auto& point : points)
    {
        std::cout << point << std::endl;
    }
}

void Polyline::ToPlan(Plan& plan) const
{
}

int  Polyline::getType() const
{
    return type;
}

std::vector<Point2d> Polyline::getPoints() const
{
    return points;
}


void Polyline::setPoint(const Point2d& point, size_t number)
{

    if (number >= points.size())
        throw std::exception("Value greater than the number of points");
    else
        points[number] = point;
}