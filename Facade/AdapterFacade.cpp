#include "AdapterFacade.h"

void AdapterFacade::deleteModel(int index)
{
    deleteIdxModel(index);
}

void AdapterFacade::CreateLightningCommand()
{
   CreateLightningFacade(model_mgr.GetIModel(0),model_mgr.GetIModel(1));
}

void AdapterFacade::DeleteLightningCommand()
{
    //qDebug("Delete lightning");
    if (lightning_mgr.getComposite()->getModelsNumber() != 0)
        DeleteLightningFacade();

}

void AdapterFacade::SetModelColorCommand(int i, QColor c)
{
    if (!model_mgr.getComposite()->getModelsNumber())
        return;

    SetNewModelColor(i, c);

}

void AdapterFacade::SetOffsetCommand(int i, double newoffset)
{
    if (!model_mgr.getComposite()->getModelsNumber())
        return;

    SetNewOffset(i, newoffset);
}

void AdapterFacade::SetLightningQualityCommand(int i, int value)
{
    if (!lightning_mgr.getComposite()->getModelsNumber())
        return;

    SetNewLightningQuality(i, value);
}

void AdapterFacade::SetLightningColorCommand(int i, QColor c)
{
    if (!lightning_mgr.getComposite()->getModelsNumber())
        return;

    SetNewLightningColor(i, c);

}

void AdapterFacade::SimulateCommand()
{
    SimulateLightning();
}

void AdapterFacade::MoveModel(int index,double x, double y, double z)
{

   if (!model_mgr.getComposite()->getModelsNumber())
       return;

   Offset offset(x,y,z);
   TransformData data;

   data.setOffset(offset);

   UpdateModel(index,data);
}

void AdapterFacade::MoveComponent(int index, double x, double y, double z)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();
    it += index;
    Offset offset(x, y, z);
    TransformData data;
    data.setOffset(offset);

    UpdateCamera(it, data);
}

void AdapterFacade::ZoomComponent(int index, double x, double y, double z)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();
    it += index;
    Zoom zoom(x, y, z);
    TransformData data;
    data.setZoom(zoom);

    UpdateCamera(it, data);
}

void AdapterFacade::RotateComponent(int index, double x, double y, double z)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();
    it += index;
    Rotate rotate(x, y, z, 0, 0, 0);
    TransformData data;
    data.setRotate(rotate);

    UpdateCamera(it, data);
}

void AdapterFacade::addModel(char* file_name)
{
    OpenStream stream;
    std::ifstream fin;
    stream.getStream(fin, file_name);
    LoadModel(fin);
    CloseStream close_stream;
    close_stream.Close(fin);
}

void AdapterFacade::addCamera()
{
    AddNewCamera();
}

void AdapterFacade::DrawScene(int camera_index, Draw* draw)
{
    if (!camera_mgr.getCameras()->Size())
        return;
    // Начало списка камер
    ListPointer<Component*>::iterator it = camera_mgr.getCameras()->begin();

    // Переходим на нужную камеру
    it += camera_index;
    //qDebug("HERE!");
    // Рисуем то, что видит нужная камера
    DrawingScene(it, draw);
}
