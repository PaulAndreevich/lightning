#include "PointsArray.h"

PointsArray::PointsArray()
{
    points = NULL;
    elements_number = 0;
}

PointsArray::PointsArray(int kol)
{
    elements_number = 0;
    set(kol);
}

PointsArray::PointsArray(const PointsArray & obj)
{
    if (!obj.points)
    {
        points = NULL;
        elements_number = 0;
    }
    else
    {
        set(obj.elements_number);

        int i = 0;
        for (i = 0; i < elements_number; i++)
            points[i].setPoint(obj.points[i].getX(),
                               obj.points[i].getY(),
                               obj.points[i].getZ());
    }
}


PointsArray::~PointsArray()
{
    Delete();
}

void PointsArray::Delete()
{
    if (points)
    {
        delete [] points;
        points = NULL;
        elements_number = 0;
    }
}

void PointsArray::appendPoint(Point newPnt)
{
    elements_number++;
    points = (Point*)realloc(points, elements_number * sizeof(Point));
    points[elements_number-1] = newPnt;
}

void PointsArray::set(int kol)
{
    if (kol > 0)
    {
        points = new (std::nothrow) Point[kol];
        if (!points)
            throw ErrorAlloc((char*)"Error allocate memory set (PointsArray)!");
        elements_number = kol;      
    }
}

void PointsArray::setIPoint(int i, Point point)
{

    if (points && i >= 0 && i < elements_number)
         points[i] = point;
}

Point PointsArray::getIPoint(int i) const
{
    if (!(points && i >= 0 && i < elements_number))
        return Point(0, 0, 0);

    return points[i];
}

PointsArray& PointsArray::operator= (const PointsArray& obj)
{
    if (&obj == this)
        return *this;

    if (points)
        Delete();

    if(obj.IsEmpty())
        return *this;

    set(obj.elements_number);

    int i = 0;
    for (i = 0; i < elements_number; i++)
        points[i].setPoint(obj.points[i].getX(),
                           obj.points[i].getY(),
                           obj.points[i].getZ());
    return *this;
}

void PointsArray::TransformIPoint(int index, const TransformMatrix& tr_matrix, bool rev)
{
    Point point = getIPoint(index);

    point = (rev == 1) ? PointsArray::TransformReversePoint(point, tr_matrix) : PointsArray::TransformPoint(point, tr_matrix);

    setIPoint(index, point);
}


Point PointsArray::TransformPoint(Point point, const TransformMatrix& tr_matrix)
{
    Point tmp = point;

    point.setX(tmp.getX() * tr_matrix.getVal(0, 0) +
               tmp.getY() * tr_matrix.getVal(1, 0) +
               tmp.getZ() * tr_matrix.getVal(2, 0) + tr_matrix.getVal(3,0));

    point.setY(tmp.getX() * tr_matrix.getVal(0, 1) +
               tmp.getY() * tr_matrix.getVal(1, 1) +
               tmp.getZ() * tr_matrix.getVal(2, 1) + tr_matrix.getVal(3,1));

    point.setZ(tmp.getX() * tr_matrix.getVal(0, 2) +
               tmp.getY() * tr_matrix.getVal(1, 2) +
               tmp.getZ() * tr_matrix.getVal(2, 2) + tr_matrix.getVal(3,2));

    return point;
}

Point PointsArray::TransformReversePoint(Point point, const TransformMatrix& tr_matrix)
{
    Point tmp = point;

    point.setX(tmp.getX() * tr_matrix.getVal(0, 0) +
               tmp.getY() * tr_matrix.getVal(0, 1) +
               tmp.getZ() * tr_matrix.getVal(0, 2) + tr_matrix.getVal(0,3));

    point.setY(tmp.getX() * tr_matrix.getVal(0, 1) +
               tmp.getY() * tr_matrix.getVal(1, 1) +
               tmp.getZ() * tr_matrix.getVal(1, 2) + tr_matrix.getVal(1,3));

    point.setZ(tmp.getX() * tr_matrix.getVal(2, 0) +
               tmp.getY() * tr_matrix.getVal(2, 1) +
               tmp.getZ() * tr_matrix.getVal(2, 2) + tr_matrix.getVal(2,3));

    Point result;
    Vec3f res3f;
    res3f = Point::ToVec3f(point).normalize();
    result.setX(res3f.x);
    result.setY(res3f.y);
    result.setZ(res3f.z);
    return point;
}

void PointsArray::Transform(const TransformMatrix& obj, bool Reverse)
{
    int i = 0;
    for (i = 0; i < elements_number; i++)
        TransformIPoint(i, obj, Reverse);
}
