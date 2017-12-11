#ifndef ROTATE_H
#define ROTATE_H

class Rotate
{
private:
    double arc_x;
    double arc_y;
    double arc_z;

    double x0,y0,z0;
public:
    Rotate() : arc_x(0.0), arc_y(0.0), arc_z(0.0), x0(0.0), y0(0.0), z0(0.0) {}
    Rotate(double x, double y, double z, double _x0, double _y0, double _z0): arc_x(x), arc_y(y), arc_z(z), x0(_x0), y0(_y0), z0(_z0) {}
    Rotate(const Rotate&);
    ~Rotate() {}
    Rotate& operator= (const Rotate&);
    Rotate operator+ (const Rotate&);

    void set_arc_x(double x) {arc_x = x;}
    void set_arc_y(double y) {arc_y = y;}
    void set_arc_z(double z) {arc_z = z;}
    double get_arc_x() const {return arc_x;}
    double get_arc_y() const {return arc_y;}
    double get_arc_z() const {return arc_z;}

    void set_x0(double x) {x0 = x;}
    void set_y0(double y) {y0 = y;}
    void set_z0(double z) {z0 = z;}
    double get_x0() const {return x0;}
    double get_y0() const {return y0;}
    double get_z0() const {return z0;}
};

#endif // ROTATE_H
