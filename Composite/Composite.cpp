#include "Composite.h"
#include "Model.h"

// it - итератор, указывающий на i-тую камеру
void Composite::Drawing(ListPointer<Component*>::iterator it, Draw* draw)
{
    //draw->settings();
    //draw->FillCanvas(QColor(80,80,80));
    if (!components.Size())
        return;

    // Проходим по всем компонентам и рисуем их
    ListPointer<Component*>::iterator iter_component = CreateComponentsIterator();
    for (; !iter_component.IsDone(); ++iter_component)
        (*iter_component)->Drawing(it, draw);
}
