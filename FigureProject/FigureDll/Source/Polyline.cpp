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
 Figure::read(provider);
 int size = provider.rdInt();

 points.reserve(size);

 for (int i = 0; i < size; i++)
 {
  auto obj = provider.rdPoint2d();
  points.push_back(obj);
 }
}


void Polyline::write(DataProvider& provider) const
{
 Figure::write(provider);
 provider.writeInt(points.size());

 for (auto point : points)
 {
  provider.writePoint2d(point);
 }
}

void Polyline::print() const
{
 Figure::print();
 std::cout << points.size() << std::endl;
 
 for (auto point : points)
 {
  std::cout << point << std::endl;
 }
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