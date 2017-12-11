#include "ModelBuilder.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

Model* ModelBuilder::getModel(std::ifstream& stream)
{
    Model* model = new Model;
    // model->setKoords(readPointsArray(stream));
    // model->setConnects(readLinesArray(stream));

    model = readObj(stream);

    if (!model)
        throw ErrorAlloc((char*)"Error allocate memory getModel!");
    return model;
}

Point ModelBuilder::readPoint(std::ifstream& stream)
{
    double x = 0, y = 0, z = 0;
    stream >> x;
    stream >> y;
    stream >> z;
    Point point(x,y,z);
    return point;
}

Line ModelBuilder::readLine(std::ifstream& stream)
{
    int begin = 0, end = 0;
    stream >> begin;
    stream >> end;
    Line line(begin, end);
    return line;
}

PointsArray ModelBuilder::readPointsArray(std::ifstream& stream)
{
    int kol_koords = 0;
    stream >> kol_koords;
    PointsArray point_array(kol_koords);
    //  if (point_array.IsEmpty())
    //    throw ErrorAlloc("Error allocate memory readPointsArray!");
    int i = 0;
    for (i = 0; i < kol_koords; i++)
    {
        Point point = readPoint(stream);
        point_array.setIPoint(i, point);
    }
    return point_array;
}

LinesArray ModelBuilder::readLinesArray(std::ifstream& stream)
{
    int kol_connects = 0;
    stream >> kol_connects;
    LinesArray lines_array(kol_connects);
    if (lines_array.IsEmpty())
        throw ErrorAlloc((char*)"Error allocate memory readLinesArray!");
    int i = 0;
    for (i = 0 ; i < kol_connects; i++)
    {
        Line line = readLine(stream);
        lines_array.setILine(i, line);
    }
    return lines_array;
}

Model* ModelBuilder::readObj(std::ifstream& in)
{
    Model* result = new Model;
    int i = 0;
    //std::ifstream in;
    //in.open (filename, std::ifstream::in);
    if (in.fail()) return result;
    std::string line;
    while (!in.eof())
    {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v "))
        {
            iss >> trash;
            Point vert;
            for (i = 0; i < 3; i++)
                iss >> vert[i];
            result->verts()->appendPoint(vert);
        }
        else if (!line.compare(0, 3, "vn "))
        {
            iss >> trash >> trash;
             Vec3f n;
            for (int i=0;i<3;i++)
               iss >> n[i];
   //         result->norms()
        }
        else if (!line.compare(0, 3, "vt "))
        {
         //   iss >> trash >> trash;
          //  Vec2f uv;
         //   for (int i=0;i<2;i++)
         //       iss >> uv[i];
         //   uv_.push_back(uv);
        }
        else if (!line.compare(0, 2, "f "))
        {
            //qDebug("F");
            Polygon *f = new Polygon;
            Vec3i tmp;
            iss >> trash;
            while (iss >> tmp[0] >> trash >> tmp[1] >> trash >> tmp[2])
            {
                for (i = 0; i < 3; i++)
                    tmp[i]--; // in wavefront obj all indices start at 1, not zero
                f->append(tmp);
            }
            result->faces()->appendPolygon(f);
        }
    }
   //std::cerr << "# v# " << result->verts()->getElementsNumber() << " f# "  << result->faces()->getElementsNumber() /*<< " vt# " << uv_.size() << " vn# " << norms_.size() */ << std::endl;
    // Сверху мы получили всю модель. Теперь здесь же сразу найдём центр.
    // Center Point
    double  xmax, ymax, zmax,
            xmin, ymin, zmin,
            x,    y,    z;

    for (i = 0; i < result->verts()->getElementsNumber(); i++)
    {
        x = result->verts()->getIPoint(i).getX();

        if ((x > xmax) || (i == 0))
            xmax = x;
        if ((x < xmin) || (i == 0))
            xmin = x;

        y = result->verts()->getIPoint(i).getY();

        if ((y > ymax) || (i == 0))
            ymax = y;
        if ((y < ymin) || (i == 0))
            ymin = y;

        z = result->verts()->getIPoint(i).getZ();

        if ((z > zmax) || (i == 0))
            zmax = z;
        if ((z < zmin) || (i == 0))
            zmin = z;
    }
    result->verts()->appendPoint(Point((xmax+xmin)/2,
                                       (ymax+ymin)/2,
                                       (zmax+zmin)/2));

    // Вычисление нормалей к каждой вершине (если vn->size == 0)
    if (result->norms()->getElementsNumber() == 0)
    {
        qDebug("Creating normales...");
        // Берём каждую точечку
        for(int i = 0; i < result->verts()->getElementsNumber(); i++)
        {
            Point p;

            Vec3f N, tmp;
            int kolvoN = 0;
            N.x = 0;
            N.y = 0;
            N.z = 0;

            // Берём каждый полигончик
            for(int j = 0; j < result->faces()->getElementsNumber(); j++)
            {
                bool IsPointIn = false;

                int polygon_power = result->faces()->getIPolygon(j)->getElementsNumber();
                Vec3f world_coords[polygon_power];

                // Проверка, есть ли точка в полигоне
                for (int k = 0; k < polygon_power; k++)
                {
                    if (i == result->faces()->getIPolygon(j)->getIVec(k)[0]) ///< Берём индексь точечьки
                    {
                        IsPointIn = true; // точечка принадлежит полигончику ^3^

                        // И поправим faсes(polygons), чтоб найти нашу будущую нормаль к точке среди других
                        result->faces()->getIPolygon(j)->setIVecJValue(k,2,i);
                    }
                }
                // если точечка внутри полигончика, [s]четвертовать[\s] нормализовать полигон
                if (IsPointIn)
                {
                    for (int k = 0; k < polygon_power; k++)
                    {
                        p = result->verts()->getIPoint(result->face(j)[k]);
                        world_coords[k] = Point::ToVec3f(p);
                    }
                   // Магия
                    tmp = (world_coords[1] - world_coords[0])^(world_coords[2] - world_coords[0]);
                    //tmp.normalize();
                    // В итоге N - куйня к одному полигону
                    // Теперь надо просуммировать к общему полигону и прибавить их кол-во
                    N = N + tmp;
                    kolvoN++;
                }
            }
            // Теперь у нас есть сумма нормалей. Осталось разделить
            if (kolvoN != 0)
            {
                N = N / kolvoN;
                N.normalize();
                // атлишнь, у нас есть N к точке
                // Пухнём её в массив vn последней, её индекс совпадет с текущим значением i
                result->norms()->appendPoint(Point(N.x, N.y, N.z));
                // Ну а массив полигонов мы уже поправили
            }
        }

    }

    return result;
}
