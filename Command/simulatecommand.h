#ifndef SIMULATECOMMAND_H
#define SIMULATECOMMAND_H

#include "Command.h"


class SimulateCommand : public Command
{
public:
    SimulateCommand() {}
    ~SimulateCommand() {}

    void execute(AdapterFacade& facade)
    {
        facade.SimulateCommand();
    }
};

#endif // SIMULATECOMMAND_H
