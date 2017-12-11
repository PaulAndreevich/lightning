#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include "Strategy/OffsetMatrix.h"
#include "Strategy/RotateMatrix.h"
#include "QColor"
#include "Camera.h"
#include "Draw/Draw.h"
#include "./Composite/point.h"

class LightSource : public Component
{
private:
    Point location;
    float baseIntensity;

public:
    LightSource() {baseIntensity = 1;}

    void setLocation(Point p)
    {
        this->location = p;
    }
    Point getLocation()
    {
        return location;
    }

    void setIntensity(float i)
    {
        if (i < 0)
            i = 0;
        baseIntensity = i;
    }

    float getIntensity()
    {
        return baseIntensity;
    }

    void Drawing(ListPointer<Component *>::iterator cam, Draw * draw)
    {
       Point temp;
       TransformMatrix matrix = (*cam)->getTransformMatrix();
       temp.Transformpoint(matrix);

       Vec3i newloc1 = draw->ProjectIntoScreen(Vec3f(ROUND(location.getX() - 1),ROUND(location.getY()),ROUND(location.getZ())));
       Vec3i newloc2 = draw->ProjectIntoScreen(Vec3f(ROUND(location.getX() + 1),ROUND(location.getY()),ROUND(location.getZ())));

       Vec3i newloc3 = draw->ProjectIntoScreen(Vec3f(ROUND(location.getX()),ROUND(location.getY() - 1),ROUND(location.getZ())));
       Vec3i newloc4 = draw->ProjectIntoScreen(Vec3f(ROUND(location.getX()),ROUND(location.getY() + 1),ROUND(location.getZ())));

       draw->DrawLine(0,newloc1,newloc2,Qt::white);
       draw->DrawLine(0,newloc3,newloc4,Qt::white);


    }
};

#endif // LIGHTSOURCE_H
