#pragma once

#include "Color.h"
#include "Platform.h"


enum class Linetype
{
    Continuous,
    Dashed,
    Dots,
    DashAndDots,
};

struct Style
{
    Style();
    Style(float thickness, Color color, Linetype linetype);

    bool operator< (const Style& style) const;

    float thickness;
    Color color;
    Linetype linetype;
};
