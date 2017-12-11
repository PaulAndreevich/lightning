#ifndef ZOOMCOMMAND_H
#define ZOOMCOMMAND_H

#include "Command.h"

class ZoomCommand : public Command
{
private:
    int index;
    double kx;
    double ky;
    double kz;
public:
    ZoomCommand(int i, double x, double y, double z): index(i), kx(x), ky(y), kz(z) {}
    ~ZoomCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.ZoomComponent(index,kx,ky,kz);
    }

};

#endif // ZOOMCOMMAND_H
