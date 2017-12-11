#ifndef MOVEMODELCOMMAND_H
#define MOVEMODELCOMMAND_H

#include "Command.h"

class MoveModelCommand: public Command
{
private:
    int index;
    double dx;
    double dy;
    double dz;
public:
    MoveModelCommand(int i, double x, double y, double z): index(i), dx(x), dy(y), dz(z) {}
    ~MoveModelCommand() {}
    void execute(AdapterFacade& facade)
    {
        facade.MoveModel(index,dx,dy,dz);
    }
};

#endif // MOVEMODELCOMMAND_H

