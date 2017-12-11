#ifndef AbstractDraw_H
#define AbstractDraw_H

#include <QPainter>
#include "zbuf.h"

class AbstractDraw
{
protected:
    QPainter* painter;
    int height;
    int width;
    ZBuf* zBuffer;

public:
    AbstractDraw() {
        qDebug("Create abstractDraw");
        zBuffer = new ZBuf(1,1); //creates Zbuf
    }
    AbstractDraw(QPainter* paint, int h, int w) : painter(paint), height(h), width(w)
    {
        if (zBuffer)
            delete zBuffer;
        zBuffer = new ZBuf(this->width, this->height);
    }
    AbstractDraw(const AbstractDraw& obj)
    {
        painter = obj.painter;
        height = obj.height;
        width = obj.width;
        if (zBuffer)
            delete zBuffer;
        zBuffer = new ZBuf(this->width, this->height);
        //zBuffer->initZBuf(INT_MIN);
    }
    AbstractDraw& operator= (const AbstractDraw& obj)
    {
        painter = obj.painter;
        height = obj.height;
        width = obj.width;
        if (zBuffer)
            delete zBuffer;
        zBuffer = new ZBuf(this->width, this->height);
        //zBuffer->initZBuf(INT_MIN);
        return *this;
    }
    ~AbstractDraw()
    {
        delete zBuffer;
    }

    virtual void settings()
    {
        painter->translate(0,height);
        painter->scale(1, -1);
    }
    virtual void DrawLine(int x1, int y1, int x2, int y2) {painter->drawLine(x1,y1,x2,y2);}
    virtual void setPainter(QPainter* paint) {painter = paint;}
    virtual void setHeight(int h)
    {
        height = h;

        if (zBuffer)
            delete zBuffer;
        zBuffer = new ZBuf(this->width, this->height);
        //zBuffer->initZBuf(INT_MIN);
    }
    virtual void setWidth(int w)
    {
        width = w;

        if (zBuffer)
            delete zBuffer;
        zBuffer = new ZBuf(this->width, this->height);
        //zBuffer->initZBuf(INT_MIN);
    }
    virtual int getHeight() {return height;}
    virtual int getWidth() {return width;}

};

#endif // AbstractDraw_H
