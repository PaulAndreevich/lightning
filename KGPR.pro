#-------------------------------------------------
#
# Project created by QtCreator 2014-04-22T16:49:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KGPR

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Composite/PointsArray.cpp \
    Composite/point.cpp \
    Composite/Model.cpp \
    Composite/LinesArray.cpp \
    Composite/Camera.cpp \
    TransformData/Zoom.cpp \
    TransformData/TransformData.cpp \
    TransformData/Rotate.cpp \
    TransformData/Offset.cpp \
    TransformMatrix/TransformMatrix.cpp \
    Facade/AdapterFacade.cpp \
    Builder/ModelBuilder.cpp \
    Composite/Composite.cpp \
    Composite/polygonsarray.cpp \
    Composite/convert.cpp \
    Composite/lightning.cpp

HEADERS  += mainwindow.h \
    Command/ZoomCommand.h \
    Command/RotateCommand.h \
    Command/MacroCommand.h \
    Command/Command.h \
    Composite/PointsArray.h \
    Composite/point.h \
    Composite/Model.h \
    Composite/line.h \
    Composite/Composite.h \
    Composite/Component.h \
    Composite/Camera.h \
    Composite/AbstractArray.h \
    List/ListPointer.h \
    List/ElemPointer.h \
    Strategy/ZoomMatrix.h \
    Strategy/TransformInterface.h \
    Strategy/StrategyTransformMatrix.h \
    Strategy/RotateMatrix.h \
    Strategy/OffsetMatrix.h \
    TransformData/Zoom.h \
    TransformData/TransformData.h \
    TransformData/Rotate.h \
    TransformData/Offset.h \
    TransformMatrix/WrongSize.h \
    TransformMatrix/TransformMatrix.h \
    TransformMatrix/NullObject.h \
    TransformMatrix/NoReverseMatrix.h \
    TransformMatrix/Matrix.h \
    TransformMatrix/InOutMatrix.h \
    TransformMatrix/ErrorPow.h \
    TransformMatrix/ErrorIndex.h \
    TransformMatrix/ErrorAlloc.h \
    TransformMatrix/DividingByZero.h \
    TransformMatrix/AbstractMatrix.h \
    TransformMatrix/AbstractError.h \
    Facade/Facade.h \
    Facade/AdapterFacade.h \
    Facade/AbstractInterface.h \
    Stream/OpenStream.h \
    Stream/CloseStream.h \
    Builder/AbstractBuilder.h \
    Builder/ModelBuilder.h \
    Draw/AbstractDraw.h \
    Draw/Draw.h \
    Memento/Memento.h \
    Command/DrawCommand.h \
    Command/AddModelCommand.h \
    Command/AddCameraCommand.h \
    Managers/basemanager.h \
    Managers/modelmanager.h \
    Managers/cameramanager.h \
    Managers/scenemanager.h \
    Composite/polygon.h \
    Composite/polygonsarray.h \
    Draw/zbuf.h \
    Command/MoveModelCommand.h \
    Composite/convert.h \
    Command/MoveCommand.h \
    Composite/lightning.h \
    Managers/lightningmanager.h \
    Command/CreateLightningCommand.h \
    Command/simulatecommand.h \
    Command/deletelightningcommand.h \
    Command/deletecommand.h \
    Composite/lightsource.h \
    Managers/lightsourcemanager.h \
    Command/setlightningcolorCommand.h \
    Command/setlightningqualityCommand.h \
    Command/setmodelcolorCommand.h \
    Command/setoffsetCommand.h

FORMS    += mainwindow.ui

