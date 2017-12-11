#include "point.h"

Point& Point::operator=(Point point)
{
    x = point.x;
    y = point.y;
    z = point.z;

    return *this;
}
