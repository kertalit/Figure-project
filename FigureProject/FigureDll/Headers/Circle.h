#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Platform.h"
#include "Figure.h"




class FIGURE_API Circle : public Figure
{

 Point2d point;
 double radius;

public:
 Circle();
 Circle(const Point2d& point, double radius);

 static const int type = 1;


 void read(DataProvider& provider) override;
 

 void write(DataProvider& provider) override;

 void print() override;

 int getType() const override;

 
 Point2d getPoint() const;
 double getRadius() const;


 void setPoint(const Point2d& point);
 void setRadius(double radius);

 

};

#endif // !_CIRCLE_H
