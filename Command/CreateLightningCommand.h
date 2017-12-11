#ifndef CREATELIGHTNINGCOMMAND_H
#define CREATELIGHTNINGCOMMAND_H

#include "Command.h"


class CreateLightningCommand: public Command
{
public:

    CreateLightningCommand() {}
    ~CreateLightningCommand() {}

    void execute(AdapterFacade& facade)
    {
        facade.CreateLightningCommand();
    }
};

#endif // CREATELIGHTNINGCOMMAND_H

