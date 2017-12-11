#include "Model.h"
#include "point.h"


Model::Model(int kol_koords, int kol_connects)
{
    setKoords(kol_koords);
    setConnects(kol_connects);
    lightsources = NULL;
}

Model::Model(const Model & obj)
{
    if (obj.polygons.IsEmpty() && obj.koordinates.IsEmpty())
    {
        polygons.Delete();
        koordinates.Delete();
    }
    else
    {
        int kol_koords = obj.koordinates.getElementsNumber();
        int kol_connects = obj.polygons.getElementsNumber();
        setKoords(kol_koords);
        setConnects(kol_connects);
        int i = 0;
        for (i = 0; i < kol_koords; i++)
            koordinates.setIPoint(i, obj.koordinates.getIPoint(i));
        for (i = 0; i < kol_connects; i++)
            polygons.setIPolygon(i, obj.polygons.getIPolygon(i));
    }
    lightsources = NULL;
}

Model& Model::operator= (const Model& obj)
{
    if(&obj == this)
        return *this;
    if (!koordinates.IsEmpty() && !polygons.IsEmpty())
        Delete();
    if (obj.polygons.IsEmpty() || obj.koordinates.IsEmpty())
        return *this;

    int kol_koords = obj.koordinates.getElementsNumber();
    int kol_connects = obj.polygons.getElementsNumber();

    setKoords(kol_koords);
    setConnects(kol_connects);
    int i = 0;
    for (i = 0; i < kol_koords; i++)
        koordinates.setIPoint(i, obj.koordinates.getIPoint(i));
    for (i = 0; i < kol_connects; i++)
        polygons.setIPolygon(i, obj.polygons.getIPolygon(i));
    return *this;
    lightsources = NULL;
}

Model::~Model()
{
    if (!koordinates.IsEmpty() && !polygons.IsEmpty())
        Delete();
}

int Model::getConnectsNumber() const
{
    return polygons.getElementsNumber();
}
int Model::getKoordsNumber() const
{
    return koordinates.getElementsNumber();
}

Point Model::getIKoord(int i) const
{
    return koordinates.getIPoint(i);
}

Polygon *Model::getIPolygon(int i) const
{
    return polygons.getIPolygon(i);
}

std::vector<int> Model::face(int idx)
{
    std::vector<int> face;
    for (int i = 0; i < (int)this->polygons[idx].size(); i++)
        face.push_back(this->polygons[idx][i][0]);
    return face;
}

void Model::setIKoord(int i, Point point)
{
    koordinates.setIPoint(i, point);
}
void Model::setINorm(int i, Point point)
{
    normales.setIPoint(i, point);
}
void Model::setIPolygon(int i, Polygon *line)
{
    polygons.setIPolygon(i, line);
}

void Model::setKoords(int kol_koords)
{
    if (kol_koords > 0)
        koordinates.set(kol_koords);
}
void Model::setConnects(int kol_connects)
{
    if (kol_connects > 0)
        polygons.set(kol_connects);
}

Point Model::GetCenterPoint()
{
    return (this->verts()->getIPoint(this->verts()->getElementsNumber()-1));
}

/*double Model::getDistance(Model *p1, Model *p2)
{
    Vec3f result;
    Vec3f one;
    Vec3f two;
    one = two;
    Point pResult;
    pResult = p1->GetCenterPoint() - p2->GetCenterPoint();
    result = Point::ToVec3f(pResult);
    return result.norm();
}*/

/*!
 * \brief Model::GetCenterPoint
 * нахождение центра
 * \param it
 * \param draw
 * \return
 */
Vec3i Model::GetTrCenterPoint(ListPointer<Component*>::iterator it, Draw* draw)
{
    // Получаем матрицу преобразований из Iтой камеры
    TransformMatrix matrix = (*it)->getTransformMatrix();
    Point CP = this->GetCenterPoint();
    //PointsArray::TransformPoint(CP,matrix);

    Vec3i resultI;
    resultI = draw->ProjectIntoScreen(Point::ToVec3f(CP));

    return resultI;
}

void Model::Delete()
{
    koordinates.Delete();
    normales.Delete();
    polygons.Delete();
}

Memento* Model::CreateMemento() const
{
    Memento* mem = new Memento(&koordinates, &polygons);
    return mem;
}

void Model::setMemento(const Memento* obj)
{
    koordinates = (obj->memento_koords);
    polygons = (obj->memento_connects);
    normales = (obj->memento_normales);
}

void Model::Drawing(ListPointer<Component*>::iterator it, Draw* draw)
{
    Point cp = this->GetCenterPoint();

    // Получаем матрицу преобразований из Iтой камеры
    TransformMatrix matrix = (*it)->getTransformMatrix();
    Vec3f light_dir;
    int i = 0, j = 0;
    int polygon_power;

    QColor curColor = modelColor;

    for (i = 0; i < polygons.getElementsNumber(); i++)
    {
        // РИСОВАНИЕ 1-го ПОЛИГОНА
        polygon_power = polygons.getIPolygon(i)->getElementsNumber();
        std::vector<int> face = this->face(i);

        Vec3i screen_coords[polygon_power];
        Vec3f world_coords[polygon_power];
        double intensity[polygon_power];

        for (j = 0; j < polygon_power; j++)
        {
            Point v = koordinates.getIPoint(face[j]);
            world_coords[j] = Point::ToVec3f(v);
            v.Transformpoint(matrix);
            screen_coords[j] = draw->ProjectIntoScreen(Point::ToVec3f(v));           

            ListPointer<Component*>::iterator it = (*lightsources).CreateComponentsIterator();
            for (; !it.IsDone(); ++it)
                {
                      LightSource *ls= ((LightSource*)(*it));
                      light_dir = (world_coords[j] - Point::ToVec3f(ls->getLocation())).normalize(ls->getIntensity());
                      float tmpIntensity = -(norm(i,j)*light_dir);

                          if (tmpIntensity < 0)
                              tmpIntensity = 0;

                      intensity[j] += tmpIntensity;
                }

            if (intensity[j] > 1)
            {
                intensity[j] = 1;
            }
            else
            if (intensity[j] < 0)
            {
                intensity[j] = 0;
            }
        }

        curColor = modelColor;

        // Триангуляция!!!

        draw->DrawTriangle(screen_coords[0], screen_coords[1], screen_coords[2], curColor,
                intensity[0], intensity[1], intensity[2]);
        if (polygons.getIPolygon(i)->getElementsNumber() > 3)
            draw->DrawTriangle(screen_coords[0], screen_coords[2], screen_coords[3], curColor,
                intensity[0], intensity[2], intensity[3]);

    }
    //setMemento(mem_model);
    //delete mem_model;
}


