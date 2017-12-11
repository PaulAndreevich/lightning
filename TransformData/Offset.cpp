#include "Offset.h"

Offset::Offset(const Offset &obj)
{
    dx = obj.get_dx();
    dy = obj.get_dy();
    dz = obj.get_dz();
}

Offset& Offset::operator= (const Offset& obj)
{
    dx = obj.get_dx();
    dy = obj.get_dy();
    dz = obj.get_dz();
    return *this;
}

Offset Offset::operator+ (const Offset& obj)
{
    Offset new_obj(obj.get_dx() + get_dx(),
                   obj.get_dy() + get_dy(),
                   obj.get_dz() + get_dz());
    return new_obj;
}
