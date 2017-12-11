#ifndef POINT_H
#define POINT_H

#include "TransformMatrix/Matrix.h"
#include "TransformMatrix/TransformMatrix.h"

class Point
{
private:
    double x;
    double y;
    double z;
public:
    Point(): x(0.0),y(0.0),z(0.0) {}
    Point(double x_val, double y_val, double z_val) {x = x_val; y = y_val; z = z_val;}
    void setPoint(double x_val, double y_val, double z_val) {x = x_val; y = y_val; z = z_val;}
    void Transformpoint(const TransformMatrix& tr_matrix)
    {
        Point tmp = this->getPoint();

        this->setX(tmp.getX() * tr_matrix.getVal(0, 0) +
                   tmp.getY() * tr_matrix.getVal(1, 0) +
                   tmp.getZ() * tr_matrix.getVal(2, 0) + tr_matrix.getVal(3,0));

        this->setY(tmp.getX() * tr_matrix.getVal(0, 1) +
                   tmp.getY() * tr_matrix.getVal(1, 1) +
                   tmp.getZ() * tr_matrix.getVal(2, 1) + tr_matrix.getVal(3,1));

        this->setZ(tmp.getX() * tr_matrix.getVal(0, 2) +
                   tmp.getY() * tr_matrix.getVal(1, 2) +
                   tmp.getZ() * tr_matrix.getVal(2, 2) + tr_matrix.getVal(3,2));

    }
    Point& operator=(Point);
    Point operator+(const Point& b) {
             Point point;
             point.setX(this->getX() + b.getX());
             point.setY(this->getY() + b.getY());
             point.setZ(this->getZ() + b.getZ());
             return point;
          }
    Point operator-(const Point& b) {
             Point point;
             point.setX(this->getX() - b.getX());
             point.setY(this->getY() - b.getY());
             point.setZ(this->getZ() - b.getZ());
             return point;
          }
    Point& operator*=(double koef)
    {
        this->setX(this->getX()*koef);
        this->setX(this->getY()*koef);
        this->setX(this->getZ()*koef);
        return *this;
    }
    Point getPoint() {return *this;}
    void setX(double value) {x = value;}
    void setY(double value) {y = value;}
    void setZ(double value) {z = value;}
    double getX() const {return x;}
    double getY() const {return y;}
    double getZ() const {return z;}

    double& operator[] (int idx) {
        switch (idx)
        {
            case 0:
              return x;
            break;
            case 1:
              return y;
            break;
            case 2:
              return z;
            break;
            default:
                break;
        }
        return x;
    }

    static Vec3f ToVec3f(Point pnt)
    {
        Vec3f result;
        int i = 0;
        for (i = 0; i < 3; i++)
            result[i] = pnt[i];
        return result;
    }
};

#endif // POINT_H
