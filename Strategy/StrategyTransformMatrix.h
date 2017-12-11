#ifndef STRATEGYTRANSFORMMATRIX_H
#define STRATEGYTRANSFORMMATRIX_H

#include "TransformMatrix/TransformMatrix.h"
#include "TransformData/TransformData.h"
#include "QDebug"

class StrategyTransformMatrix
{
public:
    virtual TransformMatrix getTransformMatrix(const TransformData&) = 0;
};

#endif // STRATEGYTRANSFORMMATRIX_H
