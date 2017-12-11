#ifndef ZOOM_H
#define ZOOM_H

class Zoom
{
private:
    double kx;
    double ky;
    double kz;
public:
    Zoom() : kx(1.0), ky(1.0), kz(1.0) {}
    Zoom(double x, double y, double z): kx(x), ky(y), kz(z) {}
    Zoom(const Zoom&);
    ~Zoom() {}
    Zoom& operator= (const Zoom&);
    Zoom operator+ (const Zoom&);
    Zoom operator* (const Zoom&);
    void set_kx(double x) {kx = x;}
    void set_ky(double y) {ky = y;}
    void set_kz(double z) {kz = z;}
    double get_kx() const {return kx;}
    double get_ky() const {return ky;}
    double get_kz() const {return kz;}
};

#endif // ZOOM_H
