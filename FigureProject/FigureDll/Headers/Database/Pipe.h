#ifndef PIPE_H
#define PIPE_H

#include "Point2d.h"
#include "Entity.h"

#include <vector>



class Pipe : public Entity
{
public:
    Pipe(double radius, double wallThickness, Point2d startPipe, Point2d endPipe);

    void readFrom(DataProvider& provider) override;
    void writeTo(DataProvider& provider) const override;

    int getType() const override;
    
    static const int type = 4;

private:
    double radius;
    double wallThickness;
    Point2d startPipe;
    Point2d endPipe;
    std::vector<double> bounds;
};
#endif // !PIPE_H
