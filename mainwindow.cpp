#include "mainwindow.h"
#include "ui_mainwindow.h"

static AdapterFacade facade;
static MacroCommand cmd_list;
static Draw *camera = new Draw();

unsigned long long tick(void)
{
unsigned long long d;

__asm__ __volatile__("rdtsc" : "=A" (d));

return d;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), timerId(0)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    image = new QImage(ui->label->width(),ui->label->height(),QImage::Format_ARGB32);
    painter = new QPainter(image);
    camera->setImage(image);
    camera->setHeight(ui->label->height());
    camera->setWidth(ui->label->width());
    ui->radioButton->setChecked(true);
    this->LoadDefault();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadDefault()
{
    AddCamera();

    cmd_list.addCommand(new AddModelCommand((char*)"sphere512.txt"));
    cmd_list.addCommand(new RotateCommand(0,3,3,3));
    cmd_list.addCommand(new AddModelCommand((char*)"sphere512.txt"));

    cmd_list.addCommand(new SetModelColorCommand(0,QColor(255,0,0)));
    cmd_list.addCommand(new SetModelColorCommand(1,QColor(0,0,255)));
    cmd_list.addCommand(new MoveModelCommand(0,3,0,0));
    cmd_list.addCommand(new MoveModelCommand(1,-3,0,0));
    cmd_list.addCommand(new ZoomCommand(0,0.216,0.216,0.216));

    cmd_list.addCommand(new SimulateCommand);
    RedrawScene();
}


void MainWindow::AddCamera()
{
    if (image && painter)
    {
        painter->end();
        delete painter;
        delete image;
    }
    image = new QImage(ui->label->width(), ui->label->height(),QImage::Format_ARGB32);
    camera->setImage(image);
    camera->setWidth(ui->label->width());
    camera->setHeight(ui->label->height());
    cmd_list.addCommand(new AddCameraCommand);
    RedrawScene();
}

void MainWindow::simulateLightning()
{
    cmd_list.addCommand(new SimulateCommand);
    this->RedrawScene();
}

void MainWindow::RedrawScene()
{
    camera->FillCanvas(QColor(80,80,80));
    cmd_list.addCommand(new DrawCommand(0, camera));
    cmd_list.execute(facade);
    cmd_list.cleanCommandList();
    ui->label->setPixmap(QPixmap::fromImage(*image));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Delete:
        cmd_list.addCommand(new DeleteCommand(0));
        break;
    }
    RedrawScene();
}

void MainWindow::on_minusZbutton_clicked()
{
    cmd_list.addCommand(new RotateCommand(0,0,0,-3));
    RedrawScene();
}

void MainWindow::on_plusZbutton_clicked()
{
    cmd_list.addCommand(new RotateCommand(0,0,0,3));
    RedrawScene();
}

void MainWindow::on_minusYbutton_clicked()
{
    cmd_list.addCommand(new RotateCommand(0,0,-3,0));
    RedrawScene();
}

void MainWindow::on_plusYbutton_clicked()
{
    cmd_list.addCommand(new RotateCommand(0,0,3,0));
    RedrawScene();
}

void MainWindow::on_minusXbutton_clicked()
{
    cmd_list.addCommand(new RotateCommand(0,-3,0,0));
    RedrawScene();
}

void MainWindow::on_plusXbutton_clicked()
{
    cmd_list.addCommand(new RotateCommand(0,3,0,0));
    RedrawScene();
}

void MainWindow::on_minusScalebutton_clicked()
{
    cmd_list.addCommand(new ZoomCommand(0,0.6,0.6,0.6));
    RedrawScene();
}

void MainWindow::on_plusScalebutton_clicked()
{  
   cmd_list.addCommand(new ZoomCommand(0,1.5,1.5,1.5));
   RedrawScene();
}

void MainWindow::on_MoveUpbutton_clicked() //камера вверх
{

    cmd_list.addCommand(new MoveCommand(0,0,-0.3,0));

    this->RedrawScene();
}

void MainWindow::on_MoveRightbutton_clicked() // камеру вправо
{
    cmd_list.addCommand(new MoveCommand(0,0.3,0,0));
    RedrawScene();
}

void MainWindow::on_MoveDownbutton_clicked() //камера вниз
{
    cmd_list.addCommand(new MoveCommand(0,0,0.3,0));
    unsigned long long int tb,ta;
    tb = tick();
    RedrawScene();
    ta = tick();
    qDebug("%llu", ta -tb);

}

void MainWindow::on_MoveForwardbutton_clicked() //камера к наблюдателю
{
   cmd_list.addCommand(new MoveCommand(0,0.3,0,0));
   RedrawScene();
}

void MainWindow::on_MovesBackwardbutton_clicked() //камера от налюдателя
{

    cmd_list.addCommand(new MoveCommand(0,-0.3,0,0));
    RedrawScene();
}

void MainWindow::on_MoveLeftbutton_2_clicked() // камеру влево
{

    cmd_list.addCommand(new MoveCommand(0,-0.3,0,0));
    RedrawScene();
}

void MainWindow::on_MoveModelUpbutton_clicked()
{
    int index;


    if (ui->radioButton->isChecked() == true) index = 0;
    if (ui->radioButton_2->isChecked() == true) index = 1;

    cmd_list.addCommand(new MoveModelCommand(index,0,-3,0));

//    ta = tick();
//    qDebug("simulation move model time: %llu", ta -tb);
    RedrawScene();
}

void MainWindow::on_MoveModelDownbutton_clicked()
{
    int index;
    if (ui->radioButton->isChecked() == true) index = 0;
    if (ui->radioButton_2->isChecked() == true) index = 1;
    cmd_list.addCommand(new MoveModelCommand(index,0,3,0));
    RedrawScene();
}

void MainWindow::on_MoveModelRightbutton_clicked()
{
    int index;

    if (ui->radioButton->isChecked() == true) index = 0;
    if (ui->radioButton_2->isChecked() == true) index = 1;

    cmd_list.addCommand(new MoveModelCommand(index,3,0,0));
    RedrawScene();
}

void MainWindow::on_MoveModelLeftbutton_clicked()
{
    int index;

    if (ui->radioButton->isChecked() == true) index = 0;
    if (ui->radioButton_2->isChecked() == true) index = 1;

    cmd_list.addCommand(new MoveModelCommand(index,-3,0,0));
    RedrawScene();
}

void MainWindow::on_MovesModelBackwardbutton_clicked()
{
    int index;

    if (ui->radioButton->isChecked() == true) index = 0;
    if (ui->radioButton_2->isChecked() == true) index = 1;

    cmd_list.addCommand(new MoveModelCommand(index,0,0,3));
    RedrawScene();
}

void MainWindow::on_MoveModelForwardbutton_clicked()
{
    int index;

    if (ui->radioButton->isChecked() == true) index = 0;
    if (ui->radioButton_2->isChecked() == true) index = 1;

    cmd_list.addCommand(new MoveModelCommand(index,0,0,-3));
    RedrawScene();
}

void MainWindow::on_pushButton_clicked() //запуск таймера для начала генерации
{
   qDebug("Starttimer");
   cmd_list.addCommand(new CreateLightningCommand());
   cmd_list.addCommand(new SetLightningColorCommand(0,QColor(132,112,255)));
   cmd_list.addCommand(new SetoffsetCommand(0,((ui->horizontalSlider->value()+ 10) / 100.0)));
   cmd_list.addCommand(new SetLightningQualityCommand(0,(static_cast<int>(((ui->horizontalSlider_2->value() + 10) / 100.0) * 8))));
   //cmd_list.addCommand(new SetLightningQuality(0,0));
   killTimer(timerId);
   timerId = startTimer(1000/60);//(ui->horizontalSlider->value() + 1)));
}

void MainWindow::on_pushButton_2_clicked()//остановка таймера и генерации
{
    qDebug("Stoptimer");
    killTimer(timerId);
    //this->RedrawScene();
}

void MainWindow::timerEvent(QTimerEvent *)
{
    simulateLightning();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    isPressed = true;
    this->setCursor(Qt::ClosedHandCursor);
    prevLocation.setX(event->pos().x());
    prevLocation.setY(event->pos().y());
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressed == true)
    {
        double ax = (event->pos().x() - prevLocation.getX()) / 15;
        double ay = (event->pos().y() - prevLocation.getY()) / 15;

        cmd_list.addCommand(new RotateCommand(0,ay,ax,0));

        this->RedrawScene();
        prevLocation.setX(event->pos().x());
        prevLocation.setY(event->pos().y());
    }
    event->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed = false;
    this->setCursor(Qt::ArrowCursor);
    prevLocation.setX(event->pos().x());
    prevLocation.setY(event->pos().y());
    event->accept();
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0)
        cmd_list.addCommand(new ZoomCommand(0,1.1,1.1,1.1));
    else if (event->delta() < 0)
        cmd_list.addCommand(new ZoomCommand(0,0.9,0.9,0.9));
    this->RedrawScene();
    event->accept();
}

void MainWindow::on_pushButton_3_clicked()
{
    cmd_list.addCommand(new DeleteLightningCommand());
    this->RedrawScene();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    cmd_list.addCommand(new SetoffsetCommand(0,(double)((ui->horizontalSlider->value()+ 10)/100.0)));
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    cmd_list.addCommand(new SetLightningQualityCommand(0,(static_cast<int>(((ui->horizontalSlider_2->value() + 10) / 100.0) * 8))));
}
