#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include "Command.h"

class DeleteCommand : public Command
{
private:
    int index; ///< Индекс удаляемой модели

public:
    DeleteCommand(int idx) {this->index = idx;}
    ~DeleteCommand() {}

    void execute(AdapterFacade& facade)
    {
        facade.deleteModel(index);
    }
};

#endif // DELETECOMMAND_H
