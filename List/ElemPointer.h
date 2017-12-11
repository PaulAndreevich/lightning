#ifndef ELEMPOINTER_H
#define ELEMPOINTER_H

#include <stdio.h>

template <class T>
class ElemPointer
{
public:
    T val;
    ElemPointer* next;

    ElemPointer() :next(NULL) {}
    ~ElemPointer()
    {
        delete val;
    }
};

#endif // ELEMPOINTER_H
