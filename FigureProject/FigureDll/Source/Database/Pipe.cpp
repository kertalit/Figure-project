#include "Pipe.h"

Pipe::Pipe(const std::string& name, double radius, double thickness, Point2d start, Point2d end)
    :Entity(name), radius(radius), thickness(thickness), start(start), end(end)
{
}

void Pipe::readFrom(DataProvider& provider)
{

}

void Pipe::writeTo(DataProvider& provider) const
{
    
}

void Pipe::calculateSegments()
{
}
