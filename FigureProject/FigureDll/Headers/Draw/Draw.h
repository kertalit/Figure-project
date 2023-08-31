#pragma once


class Draw
{
    DrawModel& _model;
    Style _currentStyle; //0* Iterator?

public:
    Draw(DrawModel&, ObjectId id(? ))....

        makeCurrent(const Style& style);

    polyline(const Polyline& pline)
    {
        _model.append(_currentStyle, pline);
    }

    using ptr = std::shared_ptr<Draw>;
};