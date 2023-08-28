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
    Color(char red, char green, char blue);

    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color ORANGE;
    static const Color YELLOW;
    static const Color BLACK;
    static const Color WHITE;

private:
    char red;
    char green;
    char blue;

    // define static consts for
    // Black, White, Red, Green etc...
};

const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::ORANGE(255, 165, 0);
const Color Color::YELLOW(255, 255, 0);
const Color Color::BLACK(0, 0, 0);
const Color Color::WHITE(255, 255, 255);


struct Style
{
    float thickness = 1.f;
    Color color = Color::RED;
    Linetype linetype = Linetype::Continuous;
}; //operator <, or hash..

