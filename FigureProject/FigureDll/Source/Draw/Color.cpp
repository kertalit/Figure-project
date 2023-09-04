#include "Color.h"

Color::Color(char red, char green, char blue)
    :red(red), green(green), blue(blue)
{

}

bool Color::operator<(const Color& color) const
{
    if (red == color.red)
    {
        if (green == color.green)
        {
            if (blue == color.blue)
            {
                return false;
            }

            return blue < color.blue;
        }

        return green < color.green;
    }

    return red < color.red;
}

bool Color::operator==(const Color& color) const
{
    return red == color.red && green == color.green && blue == color.blue;
}

const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::ORANGE(255, 165, 0);
const Color Color::YELLOW(255, 255, 0);
const Color Color::BLACK(0, 0, 0);
const Color Color::WHITE(255, 255, 255);