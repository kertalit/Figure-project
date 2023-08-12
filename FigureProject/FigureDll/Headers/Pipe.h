#ifndef PIPE_H
#define PIPE_H

#include "Point2d.h"

#include <vector>



class Pipe
{
public:
    Pipe(double radius, double wallThickness, Point2d startTube, Point2d endTube, std::vector<double> bounds);

private:
    double radius;
    double wallThickness;
    Point2d startTube;
    Point2d endTube;
    std::vector<double> bounds;
};
#endif // !PIPE_H
