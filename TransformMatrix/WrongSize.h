#ifndef WRONGSIZE_H
#define WRONGSIZE_H
#include "AbstractError.h"

class WrongSize: public AbstractError
{
public:
    WrongSize(const char* str)
    {
        int size = 0;
        if (strlen(str) < MAX_SIZE)
            size = strlen(str);
        else
            size = MAX_SIZE - 1;
        strncpy(message_error,str,size);
        message_error[size] = '\0';
    }
    char* get_error_message() {return message_error;}    
};

#endif // WRONGSIZE_H
