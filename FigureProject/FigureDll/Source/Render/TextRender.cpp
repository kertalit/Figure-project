#include "TextRender.h"
#include "RenderBase.cpp" // Discuss the error. The constructor cannot see the implementation of the base class

TextRender::TextRender(const DrawModel& model) 
    : RenderBase(model)
{

}

void TextRender::Render()
{
    for (auto& entity : _model.getDrawbless())
    {
        auto style = entity.first;
        auto& plines = entity.second;
        /*print style;
        print plines;*/
    }
}
