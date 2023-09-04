#include "Draw.h"
#include "DrawModel.h"


Draw::Draw(DrawModel& model)
    :_model(model), _currentStyle(Style())
{

}

void Draw::makeCurrent(const Style& style)
{
    _currentStyle = style;
}

void Draw::polyline(const Polyline& pline)
{
    _model.append(_currentStyle, pline);
}
