#ifndef ElemNumber_H
#define ElemNumber_H

#include <stdio.h>

template <class T>
class ElemNumber
{
public:
    T val;
    ElemNumber* next;

    ElemNumber() :next(NULL) {}
    ~ElemNumber() {}
};

#endif // ElemNumber_H
