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
};
