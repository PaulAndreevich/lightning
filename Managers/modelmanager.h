#ifndef MODELMANAGER_H
#define MODELMANAGER_H
#include "basemanager.h"
#include "Builder/ModelBuilder.h"
#include <Composite/Composite.h>

class ModelManager : public BaseManager
{
protected:
    // Композит моделей
    Composite comp;



public:
    ModelManager() {}
    void LoadModel(std::ifstream& stream)
    {
        ModelBuilder builder;
        Model* model = builder.getModel(stream);
        comp.Add(model);
    }

    void DeleteModel(int index_model)
    {
        ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
        it += (index_model);
        if (!it.IsDone())
            comp.Remove(it);
    }

    Model* GetIModel(int index_model)
    {
        ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
        it += (index_model);
        return ((Model*)(*it));
    }

    void setColor(int i, QColor c)
    {
        ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
        it += (i);

        ((Model*)(*it))->setColor(c);
    }

    void UpdateModel(int index, const TransformData& data )
    {

        if (!comp.getModelsNumber())
            return;
        ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
        it += (index);

        ((Model*)(*it))->Update(data);


    }

    Composite* getComposite()
    {
        return &comp;
    }
};

#endif // MODELMANAGER_H
