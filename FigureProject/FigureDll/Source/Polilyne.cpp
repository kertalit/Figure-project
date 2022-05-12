#include "Polilyne.h"



Polilyne::Polilyne()
{
 points.push_back(Point2d (0.0, 0.0));
}

Polilyne::Polilyne(const std::vector<Point2d>& points)
{
 
 this->points = points;

}

void Polilyne::read(DataProvider& provider)
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


void Polilyne::write(DataProvider& provider)
{
 provider.writeInt(getType());
 Figure::write(provider);
 provider.writeInt(points.size());

 for (size_t i = 0; i < points.size(); i++)
 {
  provider.writePoint2d(points[i]);
 }

}

void Polilyne::print()
{
 Figure::print();
 std::cout << points.size() << std::endl;
 
 for (size_t i = 0; i < points.size(); i++)
 {
  std::cout << points[i] << std::endl;
 }

}

int  Polilyne::getType() const
{
 return type;
}


std::vector<Point2d> Polilyne::getPoints() const
{
 return points;
}


void Polilyne::setPoint(const Point2d& point, size_t number)
{
 this->points[number - 1] = point;
}
