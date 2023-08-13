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

    static const int type = 3;

    void print() const override;
    void ToPlan(Plan& plan) const override;

    int getType() const override;

    void setPoint(const Point2d& point, size_t number);

protected:
    void writeInternal(DataProvider& provider) const override;
    void readInternal(DataProvider& provider) override;

private:
    std::vector<Point2d> points;
};

#endif // !_POLILYNE_H