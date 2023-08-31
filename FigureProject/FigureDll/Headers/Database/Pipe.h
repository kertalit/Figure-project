#ifndef PIPE_H
#define PIPE_H

#include "Entity.h"

#include <vector>



class FIGURE_API Pipe : public Entity
{
public:
    Pipe(const std::string& name, double radius, double thickness, Point2d start, Point2d end);

    void readFrom(DataProvider& provider) override;
    void writeTo(DataProvider& provider) const override;

    static const int type = 4;

private:
    double radius;
    double thickness;
    Point2d start;
    Point2d end;
};
#endif // !PIPE_H
