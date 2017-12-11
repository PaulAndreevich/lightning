#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "Command.h"

class RotateCommand: public Command
{
private:
    int index;
    double arc_x;
    double arc_y;
    double arc_z;
public:
    RotateCommand(int i, double x, double y, double z): index(i), arc_x(x), arc_y(y), arc_z(z) {}
    ~RotateCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.RotateComponent(index,arc_x,arc_y,arc_z);
    }
};

#endif // ROTATECOMMAND_H
