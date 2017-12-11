#ifndef LIGHTNING_H
#define LIGHTNING_H
#include "Model.h"
#include "math.h"


struct segment
{
    Point start;
    Point end;
};

class Lightning: public Component
{
private:
    Model* p1;

    Model* p2;

    QColor lightningColor;

    std::list<segment> segments;

    QColor color;

    double offsetmain;

    int power;


protected:
    double Randomdouble(double a, double b)
    {
        double random = ((double) rand()) / (double) RAND_MAX;
        double diff = b - a;
        double r = random * diff;
        return a + r;
    }

public:
    Lightning(Model* a, Model* b) : p1(a), p2(b) {}

    bool GetMatch()
    {
        Point begin = p1->GetCenterPoint(),
                end = p2->GetCenterPoint();
        if (fabs(begin.getX() - end.getX()) < 1 && fabs(begin.getY() - end.getY()) < 1 && fabs(begin.getZ() - end.getZ()) < 1) return 1;
        else return 0;
    }

    void setColor(QColor color)
    {
        lightningColor = color;
    }

    void setoffset(double newoffset)
    {
        offsetmain = newoffset;
    }

    void setpower(int value)
    {
        power = value;
    }

    int getpower()
    {
        return power;
    }

    void clearlightning()
    {
        segments.clear();
    }

    void simulate()
    {

        Point begin = p1->GetCenterPoint(),
                end = p2->GetCenterPoint();
            segments.clear();
            segment first;

            first.start = begin;
            first.end = end;

            //double offset = offsetmain;

            double offset = offsetmain * sqrt((first.start.getX()- first.end.getX())*(first.start.getX()- first.end.getX()) +
                                          (first.start.getY() - first.end.getY())*(first.start.getY()- first.end.getY()) +
                                          (first.start.getZ() - first.end.getZ())*(first.start.getZ() - first.end.getZ()));

            srand (static_cast <unsigned> (rand()));

            int size = 0;
            segments.push_front(first);

            for (int i = 0;i < power;i++)
            {
                std::list<segment>::iterator  it = segments.begin();

                for (size = segments.size(); size > 0; size--)
                  {
                    segment j = *it;

                    it++;

                    segments.pop_front();

                    Point mid;

                    mid.setX((j.start.getX() +j.end.getX())/2);
                    mid.setY((j.start.getY() + j.end.getY())/2);
                    mid.setZ((j.start.getZ() + j.end.getZ())/2);

                    double nx1, ny1;
                    double px1,py1,pz1;

                    double length;

                    length = sqrt((j.start.getX()- j.end.getX())*(j.start.getX()- j.end.getX()) + (j.start.getY() - j.end.getY())*(j.start.getY()- j.end.getY())
                                  + (j.start.getZ() - j.end.getZ())*(j.start.getZ() - j.end.getZ()));


                    nx1 = fabs((j.start.getX() - j.end.getX()))/length;
                    ny1 = fabs((j.start.getY() - j.end.getY()))/length;


                    px1 = ny1 * Randomdouble(-offset,offset);
                    py1 = nx1 * Randomdouble(-offset,offset);
                    pz1 = ny1 * Randomdouble(-offset,offset);

                    mid.setX(mid.getX() + px1);
                    mid.setY(mid.getY() + py1);
                    mid.setZ(mid.getZ() + pz1);

                    segment new_element;

                    if (i == 4 || i == 2)
                    {
                        Point direction;
                        Point splitEnd;

                        direction = mid - j.start;
                        Rotate rotate(Randomdouble(-16,16),Randomdouble(-16,16),Randomdouble(-16,16), 0,0,0);
                        TransformData data;
                        data.setRotate(rotate);

                        TransformMatrix data1;
                        data1 = Convert::conversion(data);

                        direction.Transformpoint(data1);
                        direction*=0.3;

                        splitEnd = direction + mid;

                        new_element.start.setX( mid.getX());
                        new_element.start.setY( mid.getY());
                        new_element.start.setZ( mid.getZ());

                        new_element.end.setX(splitEnd.getX());
                        new_element.end.setY(splitEnd.getY());
                        new_element.end.setZ(splitEnd.getZ());

                        segments.push_back(new_element);
                  }

                    new_element.start.setX( j.start.getX());
                    new_element.start.setY( j.start.getY());
                    new_element.start.setZ( j.start.getZ());

                    new_element.end.setX(mid.getX());
                    new_element.end.setY(mid.getY());
                    new_element.end.setZ(mid.getZ());

                    segments.push_back(new_element);

                    new_element.start.setX( mid.getX());
                    new_element.start.setY( mid.getY());
                    new_element.start.setZ( mid.getZ());

                    new_element.end.setX(j.end.getX());
                    new_element.end.setY(j.end.getY());
                    new_element.end.setZ(j.end.getZ());

                    segments.push_back(new_element);
                  }
                offset /=2;
            }

    }

    void Drawing(ListPointer<Component*>::iterator it, Draw* draw)
    {
            std::list<segment> trSegments;
            std::list<segment>::iterator trIt;


            int dx =  draw->getWidth()/2;
            int dy =  draw->getHeight()/2;
            TransformMatrix matrix = (*it)->getTransformMatrix();

            for (std::list<segment>::iterator i = segments.begin(); i != segments.end(); ++i)
            {
                segment seg;
                seg.start = PointsArray::TransformPoint((*i).start, matrix);
                seg.end = PointsArray::TransformPoint((*i).end, matrix);
                trSegments.push_back(seg);
            }

            trIt = trSegments.begin();
            for (std::list<segment>::iterator i = trSegments.begin(); i != trSegments.end(); ++i)
            {
                Vec3f startreal,endreal;
                Vec3i startscr,endscr;

                startreal.x = (*i).start.getX();
                startreal.y = (*i).start.getY();
                startreal.z = (*i).start.getZ();

                endreal.x = (*i).end.getX();
                endreal.y = (*i).end.getY();
                endreal.z = (*i).end.getZ();

                startscr.x = roundf((startreal.x * dx / 2) + dx);
                startscr.y = roundf((startreal.y * dy / 2) + dy);
                startscr.z = roundf(startreal.z * 250);

                endscr.x = roundf((endreal.x * dx / 2) + dx);
                endscr.y = roundf((endreal.y * dy / 2) + dy);
                endscr.z = roundf(endreal.z * 250);

                draw->DrawLine(1,startscr, endscr, lightningColor);
                draw->DrawLine(0,startscr, endscr, lightningColor);
             }

            //остановился на том, чтобы при совпадении центров молния не генерировалась
            //значит, проверять на совпадение двух центров


    }

    std::list<segment> *getSegments()
    {
        return &segments;
    }

//    Vec3f lightsource()
//    {
//        int j =0;
//        for (std::list<segment>::iterator i = trSegments.begin(); j < 200; ++i)
//        {

//        }
//    }
};

#endif // LIGHTNING_H

/*struct segment
{
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;

};

double Randomdouble(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}*/
