#include "ModelCopy.h"



//ModelCopy::ModelCopy(const Model & obj)
//{
   /* if (obj.connections.IsEmpty() && obj.koordinates.IsEmpty())
    {
       // connections.Delete();
        koordinates.Delete();
    }
    else
    {*/
       /* int kol_koords = obj.GetKoordsNumber();
        SetKoords(kol_koords);
        for (int i = 0; i < kol_koords; i++)
            koordinates.SetIPoint(i,obj.koordinates.GetIPoint(i));
        line_copy = const_cast <LinesArray*> (&obj.connections);*/
   // }
/*}

ModelCopy& ModelCopy::operator= (const Model& obj)
{
    if(&obj == this)
        return *this;
    if (!koordinates.IsEmpty())
        Delete();
    if (obj.koordinates.IsEmpty())
        return *this;

    int kol_koords = obj.koordinates.GetElementsNumber();*/
   // int kol_connects = obj.connections.GetElementsNumber();

  /*  SetKoords(kol_koords);

    for (int i = 0; i < kol_koords; i++)
        koordinates.SetIPoint(i,obj.koordinates.GetIPoint(i));
    line_copy = const_cast <LinesArray*> (&obj.connections);8*/
   // for (int i = 0; i < kol_connects; i++)
     //   connections.SetILine(i,obj.connections.GetILine(i));
   // return *this;
//}

/*void ModelCopy::Drawing(ListPointer::iterator it, Draw *draw)
{
    int dx =  draw->GetWidth()/2;
    int dy =  draw->GetHeight()/2;
    for (int i = 0; i < line_copy->GetElementsNumber(); i++)
    {
        Line line = line_copy->GetILine(i);
        int begin = line.GetBegin(), end = line.GetEnd();
        Point point_begin = koordinates.GetIPoint(begin), point_end = koordinates.GetIPoint(end);
        draw->DrawLine(dx+point_begin.GetX(),dy-point_begin.GetY(),dx+point_end.GetX(),dy-point_end.GetY());
    }
}*/
