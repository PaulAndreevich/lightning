#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "Component.h"

class Composite: public Component
{
private:   
    ListPointer<Component*> components;
public:
    Composite() {}
    ~Composite() {components.clean();}

    int getModelsNumber() {return components.Size();}

    // bool Update(ListPointer<Component*>::iterator it) {models.; return true;}

    bool Add(Component* comp) {components.push_back(comp); return true;}

    bool Remove(ListPointer<Component*>::iterator it) {components.erase(it); return true;}

    ListPointer<Component*>::iterator CreateComponentsIterator() {return components.begin();}

    void Drawing(ListPointer<Component*>::iterator, Draw * draw);
};

#endif // COMPOSITE_H
