#ifndef MODEL_H
#define MODEL_H

#include "Composite.h"
#include "LinesArray.h"
#include "PointsArray.h"
#include "polygonsarray.h"
#include "convert.h"
#include "Memento/Memento.h"
#include "Strategy/OffsetMatrix.h"
#include "Strategy/RotateMatrix.h"
#include "lightsource.h"
//#include "./Managers/lightningmanager.h"
//#include "./Managers/lightsourcearray.h"



class Model : public Component
{
private:
    /// Вершины
    PointsArray koordinates;

    /// Нормали к вершинам
    PointsArray normales;

    /// Полигоны
    PolygonsArray polygons;

    /// Цвет
    QColor modelColor;

    /// Источники света
    Composite *lightsources;

public:
    Model() {lightsources = NULL;}
    Model(int,int);
    Model(const Model&);
    ~Model();
    Model& operator=( const Model&);
    Memento* CreateMemento() const;
    void setMemento(const Memento *);
    void setLightSources(Composite *sa)
    {
        lightsources = sa;
    }

    void setColor(QColor color)
    {
        modelColor = color;
    }
    void Update(TransformData data)
    {
        this->verts()->Transform(Convert::conversion(data), 0);
        this->norms()->Transform(Convert::conversion(data), 1);
    }
    Vec3f norm(int iface, int nvert)
    {
        int idx = polygons.getIPolygon(iface)->getIVec(nvert)[2];
        return Point::ToVec3f(normales.getIPoint(idx)).normalize();
    }
    void Drawing(ListPointer<Component*>::iterator, Draw* draw);
    Point getIKoord(int) const;
    Polygon *getIPolygon(int) const;
    PointsArray* norms()
    {
        return &normales;
    }
    void setINorm(int i, Point point);
    void setIPolygon(int, Polygon *);
    std::vector<int> face(int idx);
    int getConnectsNumber() const;
    int getNormalesNumber() const
    {
        return normales.getElementsNumber();
    }
    void setIKoord(int i, Point point);
    void setNormales(const PointsArray& arr)
    {
        normales = arr;
    }
    int getKoordsNumber() const;
    bool IsEmpty() const {return (!koordinates.getElementsNumber() && !polygons.getElementsNumber()) ? true: false;}
    void setKoords(int);
    Point getINormal(int i) const
    {
        return normales.getIPoint(i);
    }
    void setConnects(int);
    void setKoords(const PointsArray& arr) {koordinates = arr;}
    void setPolygons(const PolygonsArray& arr) {polygons = arr;}
    void setNormales(int kol_normales)
    {
        if (kol_normales > 0)
            normales.set(kol_normales);
    }
    Point GetCenterPoint();
    Vec3i GetTrCenterPoint(ListPointer<Component*>::iterator it, Draw* draw);
    PointsArray *verts() {return &koordinates;}
    PolygonsArray *faces() {return &polygons;}
    void Delete();
};

#endif // MODEL_H
