#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Platform.h"
#include "Entity.h"

using  CirclePtr = std::shared_ptr<class Circle> FIGURE_API;

class FIGURE_API Circle : public Entity
{
public:
    Circle();
    Circle(const Point2d& point, double radius);

    static const int type = 1;

    void print() const override;
    void ToPlan(Plan& plan) const override;

    int getType() const override;

    void setPoint(const Point2d& point);
    void setRadius(double radius);

protected:
    void writeInternal(DataProvider& provider) const override;
    void readInternal(DataProvider& provider) override;

private:
    Point2d point;
    double radius;
};

#endif // !_CIRCLE_H
