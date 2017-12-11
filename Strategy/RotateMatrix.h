#ifndef ROTATEMATRIX_H
#define ROTATEMATRIX_H

#include "StrategyTransformMatrix.h"

class RotateMatrix: public StrategyTransformMatrix
{
public:
    ~RotateMatrix() {}

    TransformMatrix getTransformMatrix(const TransformData& obj)
    {
        TransformMatrix matr;
        Rotate rotate = obj.getRotate();

        TransformMatrix a;
        a.createMoveMatrix(-rotate.get_x0(), -rotate.get_y0(), -rotate.get_z0());


        TransformMatrix x;
        x.createRotateXMatrix(rotate.get_arc_x());
        TransformMatrix y;
        y.createRotateYMatrix(rotate.get_arc_y());
        TransformMatrix z;
        z.createRotateZMatrix(rotate.get_arc_z());

        TransformMatrix b;
        b.createMoveMatrix(rotate.get_x0(), rotate.get_y0(), rotate.get_z0());


        matr = a * z * y * x * b;
        return matr;
    }
};

#endif // ROTATEMATRIX_H
