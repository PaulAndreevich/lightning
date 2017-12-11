#ifndef CLOSESTREAM_H
#define CLOSESTREAM_H

#include <fstream>
#include <iostream>
#include "Stream.h"

class CloseStream
{
public:
    CloseStream() {}
    ~CloseStream() {}
    void Close(std::ifstream& file_in)
    {
        file_in.close();
    }
};

#endif // CLOSESTREAM_H
