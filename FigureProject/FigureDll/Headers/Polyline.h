#ifndef _POLILYNE_H
#define _POLILYNE_H

#include "Platform.h"
#include "Figure.h"
#include "Point2d.h"
#include <vector>
#include <iostream>

using  PolylinePtr = std::shared_ptr<class Polyline> FIGURE_API;

class FIGURE_API Polyline : public Figure
{
public:
    Polyline();
    Polyline(const std::vector<Point2d>& points);

    ~Polyline() override;

    static const int type = 3;

    void read(DataProvider& provider) override;
    void write(DataProvider& provider) const override;
    void print() const override;

    int getType() const override;

    std::vector<Point2d> getPoints() const;

    void setPoint(const Point2d& point, size_t number);

private:
    std::vector<Point2d> points;
};

#endif // !_POLILYNE_H