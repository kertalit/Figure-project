#ifndef PIPE_H
#define PIPE_H

#include "Point2d.h"
#include "Entity.h"

#include <vector>



class Pipe : public Entity
{
public:
    Pipe(double radius, double wallThickness, Point2d startTube, Point2d endTube, std::vector<double> bounds);

    void read(DataProvider& provider) override;
    void write(DataProvider& provider) const override;
    void print() const override;
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
