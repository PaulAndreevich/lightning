#ifndef PointsArray_H
#define PointsArray_H

#include "AbstractArray.h"
#include "TransformMatrix/TransformMatrix.h"
#include "TransformMatrix/ErrorAlloc.h"

#include "point.h"
#include <new>
#include <stdlib.h>

class PointsArray: public AbstractArray
{
private:
    Point* points;

public:
    PointsArray();
    PointsArray(int);
    PointsArray(const PointsArray &);
    ~PointsArray();

    PointsArray& operator= (const PointsArray&);
    void Transform(const TransformMatrix&, bool Reverse = false);

    void setIPoint(int, Point);
    Point getIPoint(int) const;
    void set(int);
    void Delete();
    void appendPoint(Point newPnt);
    static Point TransformPoint(Point point, const TransformMatrix& tr_matrix);
    Point TransformReversePoint(Point point, const TransformMatrix& tr_matrix);


private:
    void TransformIPoint(int, const TransformMatrix&, bool rev);
};



#endif // PointsArray_H
