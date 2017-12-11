#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include <QDebug>
#include "AbstractArray.h"
#include "TransformMatrix/Matrix.h"

class Polygon : public AbstractArray
{
private:
    Vec3i* face;

public:
    Polygon() : AbstractArray()
    {
        face = NULL;
        elements_number = 0;
    }

    ~Polygon()
    {
        Delete();
    }

    void setPolygon(Polygon *oldPoly)
    {
        Delete();

        for (int i = 0; i < oldPoly->size(); i++)
        {
            this->append(oldPoly->getIVec(i));
        }
    }

    int size()
    {
        return this->getElementsNumber();
    }

    void set(int kol)
    {
        if (kol > 0)
        {
            face = (Vec3i*)calloc(kol, sizeof(Vec3i));

            if (!face)
                throw ErrorAlloc((char*)"Error allocate memory set (PolygonsArray)!");
            elements_number = kol;
        }
    }
    void append(Vec3i newVec)
    {
        elements_number++;
        face = (Vec3i*)realloc(face, elements_number * sizeof(Vec3i));
        face[elements_number-1] = newVec;
    }

    Vec3i& operator[] (int idx)
    {
        return face[idx];
    }

    Vec3i* data()
    {
        return face;
    }

    void Delete()
    {
        if (face)
        {
            delete  face;
            face = NULL;
            elements_number = 0;
        }
    }

    Vec3i getIVec(int i) const
    {
        if (!(face && i >= 0 && i < elements_number))
            return Vec3i();

        return face[i];
    }
    void setIVec(int idx, Vec3i vec)
    {
        this->face[idx] = vec;
    }
    void setIVecJValue(int idx, int j, int value)
    {
        this->face[idx][j] = value;
    }

};

#endif // POLYGON_H
