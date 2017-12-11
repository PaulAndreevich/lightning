#ifndef OPENSTREAM_H
#define OPENSTREAM_H

#include <fstream>
#include <iostream>
#include "Stream.h"

class OpenStream
{
public:
    OpenStream() {}
    ~OpenStream() {}
    void getStream(std::ifstream& stream, char* file_name)
    {
        stream.open(file_name);
    }
};

#endif // OPENSTREAM_H
