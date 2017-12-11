#ifndef SETLIGHTNINGCOLOR_H
#define SETLIGHTNINGCOLOR_H
#include "Command.h"

class SetLightningColorCommand : public Command
{
private:
    int index;
    QColor color;
public:
    SetLightningColorCommand(int idx, QColor c): index(idx), color(c) {}
    ~SetLightningColorCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.SetLightningColorCommand(index, color);
    }
};

#endif // SETLIGHTNINGCOLOR_H
