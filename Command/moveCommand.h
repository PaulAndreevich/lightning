#ifndef MOVECOMPONENT_H
#define MOVECOMPONENT_H

#include "Command.h"

class MoveCommand: public Command
{
private:
    int index;
    double dx;
    double dy;
    double dz;
public:
    MoveCommand(int i, double x, double y, double z): index(i), dx(x), dy(y), dz(z) {}
    ~MoveCommand() {}
    void execute(AdapterFacade& facade)
    {
        //qDebug("okCommand");
        facade.MoveComponent(index,dx,dy,dz);
    }
};

#endif // MOVECOMPONENT_H

