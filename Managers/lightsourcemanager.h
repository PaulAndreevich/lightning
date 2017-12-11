#ifndef LIGHTSOURCEMANAGER_H
#define LIGHTSOURCEMANAGER_H

#include "basemanager.h"
#include "./Composite/lightsource.h"
#include "Composite/Composite.h"

class LightSourceManager : public BaseManager
{
private:
    // Список источников
    Composite sources;

public:
    LightSourceManager() {}

    void addNewSource(Point loc, float intensity = 1)
    {
//        LightSource *s = new LightSource;
//        s->setLocation(loc);
//        s->setIntensity(intensity);
       // sources.
        LightSource *s = new LightSource;
        s->setLocation(loc);
        s->setIntensity(intensity);
        sources.Add(s);
    }

    void deleteAll()
    {
        while (sources.getModelsNumber())
        {
            ListPointer<Component*>::iterator it = sources.CreateComponentsIterator();
            sources.Remove(it);
        }
    }

    Composite* getComposite()
    {
        return &sources;
    }
};

#endif // LIGHTSOURCEMANAGER_H
