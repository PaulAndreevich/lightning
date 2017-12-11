#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QSlider>
//#include "Singleton/Singleton.h"
#include "Facade/AdapterFacade.h"
#include "Command/MacroCommand.h"
#include <time.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_minusZbutton_clicked();

    void on_plusZbutton_clicked();

    void on_minusYbutton_clicked();

    void on_plusYbutton_clicked();

    void on_minusXbutton_clicked();

    void on_plusXbutton_clicked();

    void on_minusScalebutton_clicked();

    void on_plusScalebutton_clicked();

    void on_MoveUpbutton_clicked();

    void on_MoveRightbutton_clicked();

    void on_MoveDownbutton_clicked();

    void on_MoveForwardbutton_clicked();

    void on_MovesBackwardbutton_clicked();

    void on_MoveLeftbutton_2_clicked();

    void on_MoveModelUpbutton_clicked();

    void on_MoveModelDownbutton_clicked();

    void on_MoveModelRightbutton_clicked();

    void on_MoveModelLeftbutton_clicked();

    void on_MovesModelBackwardbutton_clicked();

    void on_MoveModelForwardbutton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void AddCamera();

    void RedrawScene();

    void LoadDefault();

    void timerEvent(QTimerEvent *);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void wheelEvent(QWheelEvent *event);

    void simulateLightning();

    void on_pushButton_3_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QImage *image;
    QPainter *painter;
    int timerId;
    bool isPressed;
    Point prevLocation;
public:
    void keyPressEvent(QKeyEvent*);
};

#endif // MAINWINDOW_H
