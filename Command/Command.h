#ifndef COMMAND_H
#define COMMAND_H

#include "Facade/AdapterFacade.h"

class Command
{
public:
    virtual void execute(AdapterFacade&) = 0;
    virtual ~Command() {}
};

#endif // COMMAND_H
