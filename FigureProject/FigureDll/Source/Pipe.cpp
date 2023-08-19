#include "Pipe.h"

Pipe::Pipe(double radius, double wallThickness, Point2d startTube, Point2d endTube)
    :radius(radius), wallThickness(wallThickness)
{
}

void Pipe::readFrom(DataProvider& provider)
{

}

void Pipe::writeTo(DataProvider& provider) const
{
    
}

void Pipe::toPlan(Plan& plan) const
{
}

int Pipe::getType() const
{
    return type;
}
