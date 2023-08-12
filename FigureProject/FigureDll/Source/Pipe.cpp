#include "Pipe.h"

Pipe::Pipe(double radius, double wallThickness, Point2d startTube, Point2d endTube, std::vector<double> bounds)
    :radius(radius), wallThickness(wallThickness), startTube(startTube), endTube(endTube), bounds(bounds)
{
}
