#include "Rotate.h"

Rotate::Rotate(const Rotate& obj)
{
   arc_x = obj.get_arc_x();
   arc_y = obj.get_arc_y();
   arc_z = obj.get_arc_z();

   x0 = obj.get_x0();
   y0 = obj.get_y0();
   z0 = obj.get_z0();

}

Rotate& Rotate::operator= (const Rotate& obj)
{
    arc_x = obj.get_arc_x();
    arc_y = obj.get_arc_y();
    arc_z = obj.get_arc_z();

    x0 = obj.get_x0();

    y0 = obj.get_y0();

    z0 = obj.get_z0();
    return *this;
}

Rotate Rotate::operator+ (const Rotate& obj)
{
    Rotate new_obj(obj.get_arc_x() + get_arc_x(),
                   obj.get_arc_y() + get_arc_y(),
                   obj.get_arc_z() + get_arc_z(),
                   obj.get_x0() + get_x0(),
                   obj.get_y0() + get_y0(),
                   obj.get_z0() + get_x0());
    return new_obj;
}
