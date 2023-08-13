#include "Pipe.h"

Pipe::Pipe(double radius, double wallThickness, Point2d startTube, Point2d endTube, std::vector<double> bounds)
    :radius(radius), wallThickness(wallThickness), startTube(startTube), endTube(endTube), bounds(bounds)
{
}

void Pipe::readInternal(DataProvider& provider)
{
}

void Pipe::writeInternal(DataProvider& provider) const
{
    
}

void Pipe::ToPlan(Plan& plan) const
{
}

int Pipe::getType() const
{
    return type;
}
