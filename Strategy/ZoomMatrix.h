#ifndef ZOOMMATRIX_H
#define ZOOMMATRIX_H

#include "StrategyTransformMatrix.h"

class ZoomMatrix: public StrategyTransformMatrix
{
public:
    ~ZoomMatrix() {}

    TransformMatrix getTransformMatrix(const TransformData& obj)
    {
        TransformMatrix matr;
        Zoom zoom = obj.getZoom();
        matr.createZoomMatrix(zoom.get_kx(),
                              zoom.get_ky(),
                              zoom.get_kz());
        return matr;
    }
};

#endif // ZOOMMATRIX_H
