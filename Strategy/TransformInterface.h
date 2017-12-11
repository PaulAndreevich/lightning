#ifndef TRANSFORMINTERFACE_H
#define TRANSFORMINTERFACE_H

#include "StrategyTransformMatrix.h"

class StrategyTransformMatrix;

class TransformInterface
{
private:
    StrategyTransformMatrix* pointer;

public:
    TransformInterface() {}
    ~TransformInterface()
    {
        //if(pointer)
            //delete pointer;
    }

    void setPointer(StrategyTransformMatrix* ptr)
    {
      //  if(pointer)
        //    delete pointer;
        pointer = ptr;
    }

    TransformMatrix getTransformMatrix(const TransformData& obj)
    {
        return pointer->getTransformMatrix(obj);
    }

};

#endif // TRANSFORMINTERFACE_H
