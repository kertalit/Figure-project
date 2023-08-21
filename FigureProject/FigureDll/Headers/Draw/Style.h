#pragma once


enum class Linetype
{
    Continuous,
    Dashed,
    Dots,
    DashAndDots,
};

struct Color
{
    // rgb fields,
    // define static consts for
    // Black, White, Red, Green etc...
};

struct Style
{
    float thickness = 1.f;
    Color color = Color::Black;
    Linetype linetype = Linetype::Continuous
}; //operator <, or hash..

