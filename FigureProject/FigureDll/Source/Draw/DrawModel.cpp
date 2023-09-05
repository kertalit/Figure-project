#include "DrawModel.h"

Draw::ptr DrawModel::createDraw()
{
    return std::make_shared<Draw>(*this);
}

void DrawModel::append(const Style& style, const Polyline& pline)
{
    _drawdata[style].push_back(pline);
}

std::map<Style, std::vector<Polyline>> DrawModel::getDrawbless() const
{
    return _drawdata;
}
