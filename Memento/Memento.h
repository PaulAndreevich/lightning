#ifndef MEMENTO_H
#define MEMENTO_H
#include "Composite/PointsArray.h"
#include "Composite/polygonsarray.h"

class Model;
class PointsArray;
class PolygonsArray;

class Memento
{
private:
    friend class Model;
    PointsArray memento_koords;
    PointsArray memento_normales;
    PolygonsArray memento_connects;

public:
    Memento() {}
    Memento(const PointsArray *k_obj, const PolygonsArray *c_obj)
    {
        memento_koords = *k_obj,
        memento_connects = *c_obj;
    }
    ~Memento() {memento_koords.Delete(); memento_connects.Delete();}

    void set(PointsArray k_obj, PolygonsArray c_obj, PointsArray n_obj)
    {
        memento_koords = k_obj;
        memento_connects = c_obj;
        memento_normales = n_obj;
    }


};

#endif // MEMENTO_H
