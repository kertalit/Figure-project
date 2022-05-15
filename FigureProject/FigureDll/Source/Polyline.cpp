#include "Polyline.h"



Polyline::Polyline()
{
 points.push_back(Point2d (0.0, 0.0));
}

Polyline::Polyline(const std::vector<Point2d>& points)
  :points(points)
{

}

void Polyline::read(DataProvider& provider)
{
 Figure::read(provider);
 int size = provider.rdInt();

 points.reserve(size);

 for (int i = 0; i < size; i++)
 {
  Point2d obj = provider.rdPoint2d();
  points.push_back(obj);
 }
}


void Polyline::write(DataProvider& provider) const
{
 provider.writeInt(getType());
 Figure::write(provider);
 provider.writeInt(points.size());

 for (size_t i = 0; i < points.size(); i++)
 {
  provider.writePoint2d(points[i]);
 }
}

void Polyline::print() const
{
 Figure::print();
 std::cout << points.size() << std::endl;
 
 for (size_t i = 0; i < points.size(); i++)
 {
  std::cout << points[i] << std::endl;
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
  if (number <= 0)
  {
    std::cout << "Okay, let's not change anything";
  }
  else if (number > points.size())
    throw std::exception("Value greater than the number of points");

  else this->points[number - 1] = point;
}