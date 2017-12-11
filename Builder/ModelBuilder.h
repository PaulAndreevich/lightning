#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "AbstractBuilder.h"
#include "TransformMatrix/ErrorAlloc.h"

class ModelBuilder : public AbstractBuilder
{
public:
    ModelBuilder() {}
    ~ModelBuilder() {}
    Model* getModel(std::ifstream&);
protected:
    virtual Point readPoint(std::ifstream&);
    virtual Line readLine(std::ifstream&);
    PointsArray readPointsArray(std::ifstream&);
    LinesArray readLinesArray(std::ifstream&);
    Model* readObj(std::ifstream& in);
};

#endif // MODELBUILDER_H
