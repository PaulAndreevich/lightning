#include "convert.h"

 TransformMatrix Convert::conversion(TransformData Data)
{
    TransformInterface transform_interface;
    TransformMatrix matr;

    OffsetMatrix    *om = new OffsetMatrix;
    RotateMatrix    *rm = new RotateMatrix;
    ZoomMatrix      *zm = new ZoomMatrix;

    transform_interface.setPointer(om);
    matr = transform_interface.getTransformMatrix(Data);

    transform_interface.setPointer(rm);
    matr = matr * transform_interface.getTransformMatrix(Data);

    transform_interface.setPointer(zm);
    matr = matr * transform_interface.getTransformMatrix(Data);

    delete om;
    delete rm;
    delete zm;

    return matr;
}
