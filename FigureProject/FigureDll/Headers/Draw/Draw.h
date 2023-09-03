#pragma once

#include "DrawModel.h"

class Draw
{
    DrawModel& _model;
    Style _currentStyle; //0* Iterator?

public:
    Draw(DrawModel&, ObjectId id);

    void makeCurrent(const Style& style);

    void polyline(const Polyline& pline)
    {
        _model.append(_currentStyle, pline);
    }

    using ptr = std::shared_ptr<Draw>;
};