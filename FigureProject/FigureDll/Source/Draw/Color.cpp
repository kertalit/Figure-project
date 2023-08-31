#include "Color.h"

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

Color::Color(char red, char green, char blue)
    :red(red), green(green), blue(blue)
{

}