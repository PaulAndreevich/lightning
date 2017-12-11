#ifndef ZBUF_H
#define ZBUF_H
#include "stdlib.h"
#include "QDebug"

class ZBuf
{
private:
    int width;
    int height;
    int **data;

public:
    ZBuf(int width, int height)
    {
        this->width = width;
        this->height = height;

        this->data = (int**)malloc(this->width * sizeof(int*));

        for(int i = 0; i < this->width; i++)
            this->data[i] = (int*)malloc(this->height * sizeof(int));

        initZBuf(INT_MIN);
    }

    void initZBuf(int value)
    {
        for (int i = 0; i < this->width; i++)
            for(int j = 0; j < this->height; j++)
                this->data[i][j] = value;
    }

    ~ZBuf() // destructor of Zbuffer
    {
        for(int i = 0; i < width; i++)
            free(this->data[i]);

        free(this->data);
    }

    int getWidth() {return width;}
    int getHeight() {return height;}
    int getZ(int x, int y)
    {
        if ((x >= this->width) || (y >= this->height) || (x < 0) || (y < 0))
            return INT_MAX;
        else
            return data[x][y];
    }
    void setZ(int z, int x, int y)
    {
        if (!((x >= this->width) || (y >= this->height) || (x < 0) || (y < 0)))
            data[x][y] = z;
    }

};


#endif // ZBUF_H
