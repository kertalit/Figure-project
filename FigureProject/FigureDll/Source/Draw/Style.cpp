#include "Style.h"


Style::Style(float thickness, Color color, Linetype linetype)
    :thickness(thickness), color(color), linetype(linetype)
{

}

bool Style::operator<(const Style& style) const
{
    if (linetype == style.linetype)
    {
        if (color == style.color)
        {
            if (thickness == style.thickness)
            {
                return false;
            }

            return thickness < style.thickness;
        }

        return color < style.color;
    }

    return linetype < style.linetype;
}

