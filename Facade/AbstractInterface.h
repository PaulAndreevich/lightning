#ifndef ABSTRACTINTERFACE_H
#define ABSTRACTINTERFACE_H

#include "Draw/Draw.h"
#include "Composite/Component.h"

class AbstractInterface
{
public:
    virtual void MoveComponent(int, double, double, double) = 0;
    virtual void ZoomComponent(int, double, double, double) = 0;
    virtual void RotateComponent(int, double, double, double) = 0;
    virtual void MoveModel(int,double,double,double) = 0;
    virtual void deleteModel(int) = 0;
    virtual void addModel(char*) = 0;
    virtual void addCamera() = 0;
    virtual void DrawScene(int, Draw*) = 0;
};

#endif // ABSTRACTINTERFACE_H
