#ifndef ADAPTERFACADE_H
#define ADAPTERFACADE_H

#include "Facade.h"
#include "AbstractInterface.h"
#include "Stream/CloseStream.h"
#include "Stream/OpenStream.h"
#include "Composite/lightning.h"

class AdapterFacade: private Facade, public AbstractInterface
{
public:
     AdapterFacade(){}
     ~AdapterFacade() {}

     void MoveComponent(int, double, double, double);
     void ZoomComponent(int, double, double, double);
     void RotateComponent(int, double, double, double);
     void SetModelColorCommand(int, QColor);
     void MoveModel(int, double, double, double);
     void SetLightningColorCommand(int, QColor);
     void SetOffsetCommand(int, double);
     void SetLightningQualityCommand(int, int);
     void CreateLightningCommand();
     void DeleteLightningCommand();
     void SimulateCommand();
     void addModel(char*);
     void deleteModel(int);
     void addCamera();
     void DrawScene(int,Draw*);

};

#endif // ADAPTERFACADE_H
