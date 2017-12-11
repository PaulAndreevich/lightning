#ifndef TRANSFORMDATA_H
#define TRANSFORMDATA_H

#include "Offset.h"
#include "Zoom.h"
#include "Rotate.h"

class TransformData
{
private:
    Offset offset;
    Zoom zoom;
    Rotate rotate;

public:
    TransformData()
    {
        offset.set_dx(0);
        offset.set_dy(0);
        offset.set_dz(0);

        zoom.set_kx(1);
        zoom.set_ky(1);
        zoom.set_kz(1);

        rotate.set_arc_x(0);
        rotate.set_arc_y(0);
        rotate.set_arc_z(0);
    }

    TransformData(const TransformData&);
    ~TransformData() {}
    TransformData operator+ (const TransformData&);
    TransformData& operator+= (const TransformData&);
    TransformData& operator= (const TransformData&);
    void setOffset(const Offset&);
    void setZoom(const Zoom&);
    void setRotate(const Rotate&);
    Offset getOffset() const {return offset;}
    Zoom getZoom() const {return zoom;}
    Rotate getRotate() const {return rotate;}
};

#endif // TRANSFORMDATA_H
