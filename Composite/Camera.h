#ifndef CAMERA_H
#define CAMERA_H

#include "Component.h"
#include "Model.h"
#include "Strategy/TransformInterface.h"
#include "Strategy/OffsetMatrix.h"
#include "Strategy/RotateMatrix.h"
#include "Strategy/ZoomMatrix.h"
#include "convert.h"

class Camera: public Component
{
public:
    Camera() {}
    Camera(const Camera&);
    Camera& operator= (const Camera&);
    ~Camera() {}



   TransformMatrix getTransformMatrix()
   {
     return Convert::conversion(this->Data);
   }
};

#endif // CAMERA_H
