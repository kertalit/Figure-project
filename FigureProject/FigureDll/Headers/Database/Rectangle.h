#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Entity.h"

using  RectanglePtr = std::shared_ptr<class Rectangle> FIGURE_API;

class FIGURE_API Rectangle : public Entity
{
public:
    Rectangle();
    Rectangle(const std::string& name, const Point2d& point, double length, double width);

    void readFrom(DataProvider& provider) override;
    void writeTo(DataProvider& provider) const override;
    void Draw(Draw::ptr draw) const override;

    void setPoint(const Point2d& point);
    void setLength(double lenght);
    void setWidth(double width);

    void calculateSegments();

    int getType() const override;

    static const int type = 2;

private:
    Point2d point;
    double length;
    double width;
    Polyline segments;
};
#endif // !_RECTANGLE_H