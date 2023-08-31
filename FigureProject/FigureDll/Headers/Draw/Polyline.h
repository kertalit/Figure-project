#ifndef _POLILYNE_H
#define _POLILYNE_H

#include "DataProvider.h"

#include <vector>

using  PolylinePtr = std::shared_ptr<class Polyline> FIGURE_API;

class FIGURE_API Polyline
{
public:
    Polyline();
    Polyline(const std::vector<Point2d>& points);


    void readFrom(DataProvider& provider);
    void writeTo(DataProvider& provider) const;


    void setPoint(const Point2d& point, size_t number);

private:
    std::vector<Point2d> points;
};

#endif // !_POLILYNE_H