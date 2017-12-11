#ifndef DELETELIGHTNINGCOMMAND_H
#define DELETELIGHTNINGCOMMAND_H


#include "Command.h"


class DeleteLightningCommand: public Command
{
public:

    DeleteLightningCommand() {}
    ~DeleteLightningCommand() {}

    void execute(AdapterFacade& facade)
    {
        facade.DeleteLightningCommand();
    }
};


#endif // DELETELIGHTNINGCOMMAND_H
