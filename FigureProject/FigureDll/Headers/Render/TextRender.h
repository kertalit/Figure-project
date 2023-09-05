#pragma once

#include "RenderBase.h"

class TextRender : public RenderBase
{
public:
    TextRender(const DrawModel& model);
    void Render() override;
};