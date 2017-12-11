#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include "deletecommand.h"
#include "AddCameraCommand.h"
#include "AddModelCommand.h"
#include "DrawCommand.h"
#include "MoveModelCommand.h"
#include "ZoomCommand.h"
#include "RotateCommand.h"
#include "MoveCommand.h"
#include "CreateLightningCommand.h"
#include "deletelightningcommand.h"
#include "setmodelcolorCommand.h"
#include "simulatecommand.h"
#include "setlightningcolorCommand.h"
#include "setoffsetCommand.h"
#include "setlightningqualityCommand.h"

class MacroCommand: public Command
{
private:
    ListPointer<Command*> cmd;

public:
    MacroCommand() {}
    ~MacroCommand() {cmd.clean();}

    void addCommand(Command* command) {cmd.push_back(command);}
    void cleanCommandList() {cmd.clean();}

    void execute(AdapterFacade &facade)
    {
        ListPointer<Command*>::iterator it = cmd.begin();
        for (; !it.IsDone(); ++it)
            (*it)->execute(facade);
    }

};

#endif // MACROCOMMAND_H
