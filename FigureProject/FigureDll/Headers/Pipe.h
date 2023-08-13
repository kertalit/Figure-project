#ifndef PIPE_H
#define PIPE_H

#include "Point2d.h"
#include "Entity.h"

#include <vector>



class Pipe : public Entity
{
public:
    Pipe(double radius, double wallThickness, Point2d startTube, Point2d endTube, std::vector<double> bounds);

    void readInternal(DataProvider& provider) override;
    void writeInternal(DataProvider& provider) const override;
    void ToPlan(Plan& plan) const override;

    int getType() const override;
    
    static const int type = 4;

private:
    double radius;
    double wallThickness;
    Point2d startTube;
    Point2d endTube;
    std::vector<double> bounds;
};
#endif // !PIPE_H
