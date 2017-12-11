#ifndef CONVERT_H
#define CONVERT_H

#include "Strategy/TransformInterface.h"
#include "Strategy/OffsetMatrix.h"
#include "Strategy/RotateMatrix.h"
#include "Strategy/ZoomMatrix.h"

class Convert
{
public:
    Convert() {}
    ~Convert() {}

    static TransformMatrix conversion(TransformData Data);
};
#endif // CONVERT_H

