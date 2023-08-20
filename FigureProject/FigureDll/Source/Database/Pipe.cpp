#include "Pipe.h"

Pipe::Pipe(double radius, double wallThickness, Point2d start, Point2d end)
    :radius(radius), wallThickness(wallThickness), start(start), end(end)
{
}

void Pipe::readFrom(DataProvider& provider)
{

}

void Pipe::writeTo(DataProvider& provider) const
{
    
}
