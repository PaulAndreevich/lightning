#ifndef POLYGONSARRAY_H
#define POLYGONSARRAY_H
#include "AbstractArray.h"
#include "polygon.h"
#include "TransformMatrix/TransformMatrix.h"

class PolygonsArray : public AbstractArray
{
private:
    Polygon** array;

public:
    PolygonsArray()
    {
        array = NULL;
        elements_number = 0;
    }
    PolygonsArray(int kol)
    {
        elements_number = 0;
        set(kol);
    }
    ~PolygonsArray()
    {
        Delete();
    }

    PolygonsArray(const PolygonsArray &obj)
    {
        if (!obj.array)
        {
            array = NULL;
            elements_number = 0;
        }
        else
        {
            set(obj.elements_number);

            int i = 0;
            for (i = 0; i < elements_number; i++)
                array[i]->setPolygon(obj.array[i]);
        }
    }

    PolygonsArray& operator= (const PolygonsArray& obj)
    {
        if (&obj == this)
            return *this;

        if (array)
            Delete();

        if(obj.IsEmpty())
            return *this;

        set(obj.elements_number);

        int i = 0;
        // Для каждого полигона из объекта
        for (i = 0; i < elements_number; i++)
        {
            // выделяем память под i-тый полигон
            array[i]->set(obj.array[i]->getElementsNumber());

            for (int j = 0; j < obj.array[i]->getElementsNumber(); j++)
            {
                array[i]->setIVec(j, obj.array[i]->getIVec(j));
            }

        }

        return *this;
    }


    void setIPolygon(int i, Polygon *obj)
    {
        if (array && i >= 0 && i < elements_number)
        {
            delete array[i];
            array[i] = obj;
        }
    }

    Polygon *getIPolygon(int i) const
    {
        if (!(array && i >= 0 && i < elements_number))
            return NULL;

        return array[i];
    }
    void set(int kol)
    {
        if (kol > 0)
        {
            array = (Polygon**)calloc(kol, sizeof(Polygon*));
            if (!array)
                throw ErrorAlloc((char*)"Error allocate memory set (PolygonsArray)!");

            for (int i = 0; i < kol; i++)
                array[i] = new Polygon;

            elements_number = kol;
        }
    }
    void Delete()
    {
        if (array)
        {
            for (int i = 0; i < elements_number; i++)
                delete array[i];
            delete array;
            array = NULL;
            elements_number = 0;
        }
    }
    void appendPolygon(Polygon *newPnt)
    {
        elements_number++;
        array = (Polygon**)realloc(array, elements_number * sizeof(Polygon*));
        array[elements_number-1] = newPnt;
    }

    Polygon& operator[] (int idx) {return *array[idx];}
};

#endif // POLYGONSARRAY_H
