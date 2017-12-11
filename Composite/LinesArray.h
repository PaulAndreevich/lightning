#ifndef LinesArray_H
#define LinesArray_H

#include "AbstractArray.h"
#include "line.h"
#include <new>
#include <stdlib.h>
#include "TransformMatrix/ErrorAlloc.h"

class LinesArray: public AbstractArray
{
private:
    Line* connect;  
public:
    LinesArray();
    LinesArray(int);
    LinesArray(const LinesArray&);
    ~LinesArray();

    LinesArray& operator= (const LinesArray&);

    void setILine(int, Line);
    Line getILine(int) const;

    void set(int);
    void Delete();
};

#endif // LinesArray_H
