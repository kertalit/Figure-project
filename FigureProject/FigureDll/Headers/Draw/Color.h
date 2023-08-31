#pragma once

struct Color
{
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color ORANGE;
    static const Color YELLOW;
    static const Color BLACK;
    static const Color WHITE;

    bool operator< (const Color& color) const;
    bool operator== (const Color& color) const;

private:
    Color(char red, char green, char blue);

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
