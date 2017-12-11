#ifndef NOREVERSEMATRIX_H
#define NOREVERSEMATRIX_H
#include "AbstractError.h"

class NoReverseMatrix: public AbstractError
{
public:
    NoReverseMatrix(char* str)
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

#endif // NOREVERSEMATRIX_H
