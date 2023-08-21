#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Entity.h"


using  CirclePtr = std::shared_ptr<class Circle> FIGURE_API;

class FIGURE_API Circle : public Entity
{
public:
    Circle();
    Circle(const std::string& name, const Point2d& point, double radius);

    virtual void readFrom(DataProvider& provider) override;
    virtual void writeTo(DataProvider& provider) const override;

    void setPoint(const Point2d& point);
    void setRadius(double radius);
    int getType() const override;

    static const int type = 1;

private:
    Point2d point;
    double radius;
};

#endif // !_CIRCLE_H
