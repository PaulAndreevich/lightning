#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "Command.h"
#include "Draw/Draw.h"

class DrawCommand : public Command
{
private:
    int index;
    Draw *draw;
public:
    DrawCommand(int i,  Draw* obj) {index = i; draw = obj;}
    ~DrawCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.DrawScene(index,draw);
    }
};

#endif // DRAWCOMMAND_H
