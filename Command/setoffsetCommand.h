#ifndef SETOFFSET_H
#define SETOFFSET_H
#include "Command.h"

class SetoffsetCommand: public Command
{
private:
    int index;
    double newoffset;
public:
    SetoffsetCommand(int idx, double offset): index(idx), newoffset(offset) {}
    ~SetoffsetCommand() {}

    void execute(AdapterFacade &facade)
    {
        facade.SetOffsetCommand(index, newoffset);
    }

};

#endif // SETOFFSET_H
