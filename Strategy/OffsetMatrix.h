#ifndef OFFSETMATRIX_H
#define OFFSETMATRIX_H

#include "StrategyTransformMatrix.h"

class OffsetMatrix: public StrategyTransformMatrix
{
public:
    ~OffsetMatrix() {}

    TransformMatrix getTransformMatrix(const TransformData& obj)
    {
        TransformMatrix matr;
        Offset offset = obj.getOffset();
        matr.createMoveMatrix(offset.get_dx(),
                              offset.get_dy(),
                              offset.get_dz());
        return matr;
    }
};

#endif // OFFSETMATRIX_H
