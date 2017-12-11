#ifndef OFFSET_H
#define OFFSET_H

class Offset
{
private:
    double dx;
    double dy;
    double dz;
public:
    Offset() : dx(0.0), dy(0.0), dz(0.0) {}
    Offset(double x, double y, double z): dx(x), dy(y), dz(z) {}
    Offset(const Offset&);
    ~Offset() {}
    Offset& operator= (const Offset&);
    Offset operator+ (const Offset&);
    void set_dx(double x) {dx = x;}
    void set_dy(double y) {dy = y;}
    void set_dz(double z) {dz = z;}
    double get_dx() const {return dx;}
    double get_dy() const {return dy;}
    double get_dz() const {return dz;}
};

#endif // OFFSET_H
