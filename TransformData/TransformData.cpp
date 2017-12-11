#include "TransformData.h"

TransformData::TransformData(const TransformData& obj)
{
    offset = obj.getOffset();
    zoom = obj.getZoom();
    rotate = obj.getRotate();
}


void TransformData::setOffset(const Offset &obj)
{
    offset = obj;
}

void TransformData::setRotate(const Rotate & obj)
{
    rotate = obj;
}

void TransformData::setZoom(const Zoom & obj)
{
    zoom = obj;
}

TransformData TransformData::operator + (const TransformData& obj)
{
    TransformData new_obj;
    new_obj.setOffset(obj.getOffset() + getOffset());
    new_obj.setRotate(obj.getRotate() + getRotate());
    new_obj.setZoom(obj.getZoom() * getZoom());
    return new_obj;
}

TransformData& TransformData::operator+= (const TransformData& obj)
{
    Zoom zoom = obj.getZoom();
    if ((zoom.get_kx() != 0) && (zoom.get_ky() != 0) && (zoom.get_kz() != 0))
        *this = *this + obj;
    return *this;
}

TransformData& TransformData::operator= (const TransformData& obj)
{
    offset = obj.getOffset();
    zoom = obj.getZoom();
    rotate = obj.getRotate();
    return *this;
}
