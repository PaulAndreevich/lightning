#include "Zoom.h"

Zoom::Zoom(const Zoom& obj)
{
    kx = obj.get_kx();
    ky = obj.get_ky();
    kz = obj.get_kz();
}

Zoom& Zoom::operator= (const Zoom& obj)
{
    kx = obj.get_kx();
    ky = obj.get_ky();
    kz = obj.get_kz();
    return *this;
}

Zoom Zoom::operator+ (const Zoom& obj)
{
    Zoom new_obj(obj.get_kx() + get_kx(), obj.get_ky() + get_ky(), obj.get_kz() + get_kz());
    return new_obj;
}

Zoom Zoom::operator* (const Zoom& obj)
{
    Zoom new_obj(obj.get_kx() * get_kx(), obj.get_ky() * get_ky(), obj.get_kz() * get_kz());
    return new_obj;
}


