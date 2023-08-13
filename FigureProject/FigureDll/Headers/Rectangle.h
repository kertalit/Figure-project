#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Platform.h"
#include "Entity.h"

using  RectanglePtr = std::shared_ptr<class Rectangle> FIGURE_API;

class FIGURE_API Rectangle : public Entity
{
public:
    Rectangle();
    Rectangle(const Point2d& point, double length, double width);

    static const int type = 2;

    void print() const override;
    void ToPlan(Plan& plan) const override;

    int getType() const override;

    void setPoint(const Point2d& point);
    void setLength(double lenght);
    void setWidth(double width);

protected:
    void writeInternal(DataProvider& stream) const override;
    void readInternal(DataProvider& stream) override;

private:
    Point2d point;
    double length;
    double width;
};
#endif // !_RECTANGLE_H