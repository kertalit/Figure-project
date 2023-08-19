#ifndef _POLILYNE_H
#define _POLILYNE_H

#include "Platform.h"
#include "Entity.h"
#include "Point2d.h"
#include <vector>
#include <iostream>

using  PolylinePtr = std::shared_ptr<class Polyline> FIGURE_API;

class FIGURE_API Polyline : public Entity
{
public:
    Polyline();
    Polyline(const std::vector<Point2d>& points);


    void readFrom(DataProvider& provider) override;
    void writeTo(DataProvider& provider) const override;
    void toPlan(Plan& plan) const override;

    int getType() const override;

    void setPoint(const Point2d& point, size_t number);

    static const int type = 3;

private:
    std::vector<Point2d> points;
};

#endif // !_POLILYNE_H