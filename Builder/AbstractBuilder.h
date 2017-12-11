#ifndef ABSTRACTBULIDER_H
#define ABSTRACTBULIDER_H

#include <fstream>
#include <iostream>
#include "Composite/Model.h"

class AbstractBuilder
{
public:
    virtual Model* getModel(std::ifstream&) = 0;
};

#endif // ABSTRACTBULIDER_H
