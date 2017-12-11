#ifndef ADDMODELCOMMAND_H
#define ADDMODELCOMMAND_H

#include "Command.h"

class AddModelCommand: public Command
{
private:
    char* file_name;

public:
    AddModelCommand(char* str): file_name(str) {}
    ~AddModelCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.addModel(file_name);
    }
};

#endif // ADDMODELCOMMAND_H
