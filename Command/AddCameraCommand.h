#ifndef ADDCAMERACOMMAND_H
#define ADDCAMERACOMMAND_H

#include "Command.h"

class AddCameraCommand: public Command
{
public:
    AddCameraCommand() {}
    ~AddCameraCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.addCamera();
    }
};

#endif // ADDCAMERACOMMAND_H
