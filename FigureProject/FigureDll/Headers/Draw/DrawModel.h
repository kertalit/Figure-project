#ifndef DRAWMODEL_H
#define DRAWMODEL_H

#include <map>

#include "Draw.h"
#include "Polyline.h"
#include "Style.h"

class Draw;

class DrawModel
{
public:
    Draw::ptr createDraw();
    void append(const Style& style, const Polyline& pline);

    //_drawdata readonly access...
    //1* access culled drawables..
    //2* selection, markers, etc..
private:
    std::map<Style, std::vector<Polyline>> _drawdata;
};

#endif // !DRAWMODEL_H
