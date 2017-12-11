#include "Camera.h"

Camera::Camera(const Camera& obj)
{
    Data = obj.Data;
}

Camera& Camera::operator= (const Camera& obj)
{
    Data = obj.Data;
    return *this;
}



