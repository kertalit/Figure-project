#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Platform.h"
#include "Figure.h"

class FIGURE_API Rectangle : public Figure
{
private:

  Point2d point;
  double length;
  double width;

public:
  Rectangle();
  Rectangle(const Point2d& point, double length, double width);

  static const int type = 2;

  void read(DataProvider& file) override;

  void write(DataProvider& file) override;

  void print() override;

  int getType() const override;
  Point2d getPoint() const;
  Point2d getPoint() const;
  double getLength() const;
  double getWidth() const;

  void setPoint(const Point2d& point);
  void setLength(double lenght);
  void setWidth(double width);


};
#endif // !_RECTANGLE_H