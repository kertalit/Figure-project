#include "Commands.h"

EntityPtr createObj(size_t type)
{
    switch (type)
    {
    case Circle::type:
        return std::make_shared<Circle>();

    case Rectangle::type:
        return std::make_shared<Rectangle>();

    case Polyline::type:
        return std::make_shared<Polyline>();

    default:
        throw std::exception("Wrong format");
    }
}


