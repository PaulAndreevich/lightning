#include "LinesArray.h"

LinesArray::LinesArray()
{
    connect = NULL;
    elements_number = 0;
}

LinesArray::LinesArray(int kol)
{
    elements_number = 0;
    set(kol);
   // elements_number = kol;
}

LinesArray::LinesArray(const LinesArray & obj)
{
    if (!obj.connect)
    {
        connect = NULL;
        elements_number = 0;
    }
    else
    {
        set(obj.elements_number);
        int i = 0;
        for (i = 0; i < elements_number; i++)
            connect[i].setLine(obj.connect[i].getBegin(),obj.connect[i].getEnd());
    }
}

LinesArray::~LinesArray()
{
    Delete();
}

void LinesArray::set(int kol)
{
    if (kol > 0)
    {
        //if (connect)
         //   Delete();
        connect = new (std::nothrow) Line[kol];
     //   if (!connect)
        //    throw ErrorAlloc("Error allocate memory set (LinesArray)!");
        elements_number = kol;       
    }
}

void LinesArray::Delete()
{
    if (connect)
    {
        delete [] connect;
        connect = NULL;
        elements_number = 0;
    }
}

void LinesArray::setILine(int i, Line line)
{
    if (connect && i >= 0 && i < elements_number)
         connect[i] = line;
}

Line LinesArray::getILine(int i) const
{
    if (connect && i >= 0 && i < elements_number)
        return connect[i];
}

LinesArray& LinesArray::operator= (const LinesArray& obj)
{
    if (&obj == this)
        return *this;
    if (connect)
        Delete();
    if(obj.IsEmpty())
        return *this;
    set(obj.elements_number);
    int i = 0;
    for (i = 0; i < elements_number; i++)
        connect[i].setLine(obj.connect[i].getBegin(),obj.connect[i].getEnd());
    return *this;
}
