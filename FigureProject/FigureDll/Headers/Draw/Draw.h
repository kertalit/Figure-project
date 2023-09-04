#pragma once
#include "Style.h"
#include "Polyline.h"

class DrawModel;

class Draw
{
public:
    Draw(DrawModel& model);

    void makeCurrent(const Style& style);

    void polyline(const Polyline& pline);

    using ptr = std::shared_ptr<Draw>;

private:
    DrawModel& _model;
    Style _currentStyle; //0* Iterator?
};