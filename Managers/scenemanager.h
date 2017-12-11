#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "basemanager.h"
#include "./Composite/Model.h"
#include "Composite/Composite.h"

class SceneManager : public BaseManager
{

public:
    SceneManager() {}
    void DrawingScene(Composite* bolts, Composite *comp, ListPointer<Component*>::iterator it, Draw* draw, Composite *sources)
    {
        draw->FillCanvas(QColor(30,30,30));

        ListPointer<Component*>::iterator itModels = comp->CreateComponentsIterator();

        for(; !itModels.IsDone(); ++itModels)
            ((Model*)(*itModels))->setLightSources(sources);

        comp->Drawing(it, draw);

        if (bolts->getModelsNumber() > 0)
            bolts->Drawing(it,draw);
    }
};

#endif // SCENEMANAGER_H
