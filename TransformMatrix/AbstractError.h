#ifndef ABSTRACTERROR_H
#define ABSTRACTERROR_H

#include <string.h>

const int MAX_SIZE = 512;

class AbstractError
{
protected:
    char message_error[MAX_SIZE];
public:    
    virtual char* get_error_message() = 0;
};

#endif // ABSTRACTERROR_H
