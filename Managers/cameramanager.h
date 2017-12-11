#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H
#include "basemanager.h"
#include "Composite/Camera.h"

class CameraManager : public BaseManager
{
protected:
    // Список камер
    ListPointer<Component*> cameras;

public:
    CameraManager() {}
    void UpdateCamera(ListPointer<Component*>::iterator it, const TransformData& data)
    {

        if (!cameras.Size())
            return;
        (*it)->Update(data);

    }
    void AddNewCamera()
    {

        Camera* camera = new Camera;
        cameras.push_back(camera);

    }
    ListPointer<Component*>* getCameras()
    {
        return &cameras;
    }
};

#endif // CAMERAMANAGER_H
