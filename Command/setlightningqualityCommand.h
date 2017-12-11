#ifndef SETLIGHTNINGQUALITY_H
#define SETLIGHTNINGQUALITY_H
#include "Command.h"

class SetLightningQualityCommand: public Command
{
private:
    int index;
    int power;
public:
    SetLightningQualityCommand(int idx, int value): index(idx), power(value) {}
    ~SetLightningQualityCommand() {}

    void execute(AdapterFacade &facade)
    {
        facade.SetLightningQualityCommand(index, power);
    }
};

#endif // SETLIGHTNINGQUALITY_H
