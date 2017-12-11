#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include "basemanager.h"
#include <Composite/Composite.h>
#include "Composite/lightning.h"

#define LIGHTNING(a) ((Lightning*)(*a))


class LightningManager: public BaseManager
{
private:
    Composite lightnings;


public:
    LightningManager() {}

    void CreateLightning(Model* a, Model* b)
    {
       // qDebug("create lightning from LineMgr");
        if (lightnings.getModelsNumber() == 0)
        {
            Lightning* lightning = new Lightning(a, b);
            lightnings.Add(lightning);
        }
    }

    void DeleteLightning()
    {
        ListPointer<Component*>::iterator it = lightnings.CreateComponentsIterator();
        do
        {
            lightnings.Remove(it);
            it++;
        }while (it.IsDone());
    }

    /*!
     * \brief simulate
     * внутри просчет всех новых положений молнии во всех компонентах композита
     */
    void simulate()
    {
        //qDebug("simulate in lightning");
        ListPointer<Component*>::iterator it = lightnings.CreateComponentsIterator();
        int i = 0;
        if (lightnings.getModelsNumber() != 0)
        {
            if (LIGHTNING(it)->GetMatch() == 1)
                {
                    LIGHTNING(it)->clearlightning();
                }
            else
                {
                    for(; i < lightnings.getModelsNumber(); i++, it++)
                        {                                
                                LIGHTNING(it)->simulate();                               
                        }
                }
        }
    }

    void setOffset(int i, double newoffset)
    {
        ListPointer<Component*>::iterator it =lightnings.CreateComponentsIterator();
        it += (i);

        ((Lightning*)(*it))->setoffset(newoffset);
    }

    void setQuality(int i, int value)
    {
        ListPointer<Component*>::iterator it =lightnings.CreateComponentsIterator();
        it += (i);

        ((Lightning*)(*it))->setpower(value);
    }

    void setColor(int i, QColor c)
    {
        ListPointer<Component*>::iterator it =lightnings.CreateComponentsIterator();
        it += (i);

        ((Lightning*)(*it))->setColor(c);
    }

    Composite* getComposite()
    {
        return &lightnings;
    }
};

#endif // LINEMANAGER_H

