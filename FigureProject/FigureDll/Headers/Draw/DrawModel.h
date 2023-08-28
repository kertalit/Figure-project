#ifndef DRAWMODEL_H
#define DRAWMODEL_H

#include <map>

#include "Polyline.h"
#include "Style.h"
#include "Draw.h"


class DrawModel
{

    //...
    std::map<Style, std::vector<Polyline>> _drawdata;
    //...
public:
    Draw::ptr createDraw(ObjectId id(? ? ))
    {
        return std::make_shared<Draw>(*this, id);
    }

    //_drawdata readonly access...
    //1* access culled drawables..
    //2* selection, markers, etc..
};

#endif // !DRAWMODEL_H
