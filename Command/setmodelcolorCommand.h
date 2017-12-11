#ifndef SETMODELCOLOR_H
#define SETMODELCOLOR_H
#include "Command.h"

class SetModelColorCommand : public Command
{
private:
    int index;
    QColor color;
public:
    SetModelColorCommand(int idx, QColor c): index(idx), color(c) {}
    ~SetModelColorCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.SetModelColorCommand(index, color);
    }
};

#endif // SETMODELCOLOR_H
