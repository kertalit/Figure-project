#include "Commands.h"

ObjectPtr createObj(size_t type)
{
    switch (type)
    {
    case Circle::type:
        return std::make_shared<Circle>();

    case Rectangle::type:
        return std::make_shared<Rectangle>();

    default:
        throw std::exception("Wrong format");
    }
}


