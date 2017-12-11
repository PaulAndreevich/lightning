#ifndef FACADE_H
#define FACADE_H

#include "Composite/Composite.h"
#include "Composite/Camera.h"
#include "Builder/ModelBuilder.h"
#include "Managers/modelmanager.h"
#include "Managers/cameramanager.h"
#include "Managers/scenemanager.h"
#include "Managers/lightningmanager.h"
#include "Managers/lightsourcemanager.h"

class Facade
{
protected:
    ModelManager model_mgr;
    CameraManager camera_mgr;
    SceneManager scene_mgr;
    LightningManager lightning_mgr;
    LightSourceManager lightsource_mgr;

public:
    Facade() {}
    ~Facade() {}

    void CreateLightningFacade(Model* a, Model* b)
    {
        lightning_mgr.CreateLightning(a,b);
    }

    void DeleteLightningFacade()
    {       
        lightning_mgr.DeleteLightning();
        lightsource_mgr.deleteAll();
    }

    void SimulateLightning()
    {
        lightning_mgr.simulate();

        lightsource_mgr.deleteAll();
        ListPointer<Component*>::iterator it = lightning_mgr.getComposite()->CreateComponentsIterator();
        for (; !it.IsDone(); ++it)
        {
            std::list<segment>::iterator cur = ((Lightning*)(*it))->getSegments()->begin();
            //int light = ((Lightning*)(*it))->getpower();

            for(unsigned int segIdx = 1; segIdx < ((Lightning*)(*it))->getSegments()->size(); segIdx++, ++cur)
            {
                segment cur_seg = (*cur);
                if (!(segIdx % 10))
                    lightsource_mgr.addNewSource(cur_seg.start);
            }
        }
    }

    void SetNewLightningColor(int i,QColor c)
    {
        lightning_mgr.setColor(i,c);
    }

    void SetNewLightningQuality(int i, int value)
    {
        lightning_mgr.setQuality(i,value);
    }
    void SetNewOffset(int i, double newoffset)
    {
        lightning_mgr.setOffset(i,newoffset);
    }

    ///************************************

    void SetNewModelColor(int i, QColor c)
    {
        model_mgr.setColor(i, c);
    }

    void LoadModel(std::ifstream& stream)
    {
        model_mgr.LoadModel(stream);
    }

    void deleteIdxModel(int index_model)
    {
        model_mgr.DeleteModel(index_model);
    }

    void UpdateModel(int index, const TransformData& data)
    {
        model_mgr.UpdateModel(index,data);
    }

    ///************************************
    void UpdateCamera(ListPointer<Component*>::iterator it, const TransformData& data)
    {
        camera_mgr.UpdateCamera(it, data);
    }
    void AddNewCamera()
    {
        camera_mgr.AddNewCamera();
    }

    ///************************************
    void DrawingScene(ListPointer<Component*>::iterator it, Draw* draw)
    {

        scene_mgr.DrawingScene(lightning_mgr.getComposite(), model_mgr.getComposite()/*, lightsource_mgr.getComposite(),*/, it, draw, lightsource_mgr.getComposite());
    }
};

#endif // FACADE_H
