/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *LoadModel;
    QAction *actionHelp;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_8;
    QPushButton *MoveUpbutton;
    QPushButton *MoveLeftbutton_2;
    QPushButton *MoveRightbutton;
    QPushButton *MoveDownbutton;
    QPushButton *MoveForwardbutton;
    QPushButton *MovesBackwardbutton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *minusXbutton;
    QPushButton *plusXbutton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QPushButton *minusYbutton;
    QPushButton *plusYbutton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QPushButton *minusZbutton;
    QPushButton *plusZbutton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QPushButton *plusScalebutton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *minusScalebutton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_23;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *MoveModelUpbutton;
    QPushButton *MoveModelRightbutton;
    QPushButton *MoveModelForwardbutton;
    QPushButton *MovesModelBackwardbutton;
    QPushButton *MoveModelLeftbutton;
    QPushButton *MoveModelDownbutton;
    QLabel *label_24;
    QLabel *label_6;
    QSlider *horizontalSlider;
    QLabel *label_13;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_21;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_9;
    QSlider *horizontalSlider_2;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(889, 678);
        LoadModel = new QAction(MainWindow);
        LoadModel->setObjectName(QStringLiteral("LoadModel"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 681, 661));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(690, 10, 161, 16));
        MoveUpbutton = new QPushButton(centralWidget);
        MoveUpbutton->setObjectName(QStringLiteral("MoveUpbutton"));
        MoveUpbutton->setGeometry(QRect(750, 30, 61, 31));
        MoveLeftbutton_2 = new QPushButton(centralWidget);
        MoveLeftbutton_2->setObjectName(QStringLiteral("MoveLeftbutton_2"));
        MoveLeftbutton_2->setGeometry(QRect(720, 60, 31, 31));
        QFont font;
        font.setPointSize(10);
        MoveLeftbutton_2->setFont(font);
        MoveRightbutton = new QPushButton(centralWidget);
        MoveRightbutton->setObjectName(QStringLiteral("MoveRightbutton"));
        MoveRightbutton->setGeometry(QRect(810, 60, 31, 31));
        MoveRightbutton->setFont(font);
        MoveDownbutton = new QPushButton(centralWidget);
        MoveDownbutton->setObjectName(QStringLiteral("MoveDownbutton"));
        MoveDownbutton->setGeometry(QRect(750, 90, 61, 31));
        MoveForwardbutton = new QPushButton(centralWidget);
        MoveForwardbutton->setObjectName(QStringLiteral("MoveForwardbutton"));
        MoveForwardbutton->setGeometry(QRect(750, 60, 31, 31));
        QFont font1;
        font1.setPointSize(12);
        MoveForwardbutton->setFont(font1);
        MovesBackwardbutton = new QPushButton(centralWidget);
        MovesBackwardbutton->setObjectName(QStringLiteral("MovesBackwardbutton"));
        MovesBackwardbutton->setGeometry(QRect(780, 60, 31, 31));
        QFont font2;
        font2.setPointSize(16);
        MovesBackwardbutton->setFont(font2);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(690, 130, 191, 102));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        minusXbutton = new QPushButton(layoutWidget);
        minusXbutton->setObjectName(QStringLiteral("minusXbutton"));

        horizontalLayout->addWidget(minusXbutton);

        plusXbutton = new QPushButton(layoutWidget);
        plusXbutton->setObjectName(QStringLiteral("plusXbutton"));

        horizontalLayout->addWidget(plusXbutton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        minusYbutton = new QPushButton(layoutWidget);
        minusYbutton->setObjectName(QStringLiteral("minusYbutton"));

        horizontalLayout_2->addWidget(minusYbutton);

        plusYbutton = new QPushButton(layoutWidget);
        plusYbutton->setObjectName(QStringLiteral("plusYbutton"));

        horizontalLayout_2->addWidget(plusYbutton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        minusZbutton = new QPushButton(layoutWidget);
        minusZbutton->setObjectName(QStringLiteral("minusZbutton"));

        horizontalLayout_3->addWidget(minusZbutton);

        plusZbutton = new QPushButton(layoutWidget);
        plusZbutton->setObjectName(QStringLiteral("plusZbutton"));

        horizontalLayout_3->addWidget(plusZbutton);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(690, 240, 191, 71));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        plusScalebutton = new QPushButton(layoutWidget1);
        plusScalebutton->setObjectName(QStringLiteral("plusScalebutton"));

        verticalLayout_2->addWidget(plusScalebutton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        minusScalebutton = new QPushButton(layoutWidget1);
        minusScalebutton->setObjectName(QStringLiteral("minusScalebutton"));

        horizontalLayout_4->addWidget(minusScalebutton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(700, 580, 181, 96));
        verticalLayout_7 = new QVBoxLayout(layoutWidget2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget2);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout_7->addWidget(label_23);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_7->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_7->addWidget(pushButton_3);

        MoveModelUpbutton = new QPushButton(centralWidget);
        MoveModelUpbutton->setObjectName(QStringLiteral("MoveModelUpbutton"));
        MoveModelUpbutton->setGeometry(QRect(750, 480, 61, 31));
        MoveModelRightbutton = new QPushButton(centralWidget);
        MoveModelRightbutton->setObjectName(QStringLiteral("MoveModelRightbutton"));
        MoveModelRightbutton->setGeometry(QRect(810, 510, 31, 31));
        MoveModelRightbutton->setFont(font);
        MoveModelForwardbutton = new QPushButton(centralWidget);
        MoveModelForwardbutton->setObjectName(QStringLiteral("MoveModelForwardbutton"));
        MoveModelForwardbutton->setGeometry(QRect(750, 510, 31, 31));
        MoveModelForwardbutton->setFont(font1);
        MovesModelBackwardbutton = new QPushButton(centralWidget);
        MovesModelBackwardbutton->setObjectName(QStringLiteral("MovesModelBackwardbutton"));
        MovesModelBackwardbutton->setGeometry(QRect(780, 510, 31, 31));
        MovesModelBackwardbutton->setFont(font2);
        MoveModelLeftbutton = new QPushButton(centralWidget);
        MoveModelLeftbutton->setObjectName(QStringLiteral("MoveModelLeftbutton"));
        MoveModelLeftbutton->setGeometry(QRect(720, 510, 31, 31));
        MoveModelLeftbutton->setFont(font);
        MoveModelDownbutton = new QPushButton(centralWidget);
        MoveModelDownbutton->setObjectName(QStringLiteral("MoveModelDownbutton"));
        MoveModelDownbutton->setGeometry(QRect(750, 540, 61, 31));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(690, 460, 131, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(690, 390, 61, 20));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(690, 330, 191, 20));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(680, 310, 201, 20));
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(710, 410, 146, 48));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_21 = new QLabel(layoutWidget3);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout_4->addWidget(label_21);

        label_22 = new QLabel(layoutWidget3);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_4->addWidget(label_22);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton = new QRadioButton(layoutWidget3);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);


        horizontalLayout_5->addLayout(verticalLayout_3);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(690, 350, 161, 16));
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(690, 370, 191, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 889, 20));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\215\320\273. \321\200\320\260\320\267\321\200\321\217\320\264\320\276\320\262", 0));
        LoadModel->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        label->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213: ", 0));
        MoveUpbutton->setText(QApplication::translate("MainWindow", "/\\", 0));
        MoveLeftbutton_2->setText(QApplication::translate("MainWindow", "<", 0));
        MoveRightbutton->setText(QApplication::translate("MainWindow", ">", 0));
        MoveDownbutton->setText(QApplication::translate("MainWindow", "\\/", 0));
        MoveForwardbutton->setText(QApplication::translate("MainWindow", "o", 0));
        MovesBackwardbutton->setText(QApplication::translate("MainWindow", "+", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 \320\262\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\265\320\271:", 0));
        label_2->setText(QApplication::translate("MainWindow", "X:", 0));
        minusXbutton->setText(QApplication::translate("MainWindow", "-", 0));
        plusXbutton->setText(QApplication::translate("MainWindow", "+", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y:", 0));
        minusYbutton->setText(QApplication::translate("MainWindow", "-", 0));
        plusYbutton->setText(QApplication::translate("MainWindow", "+", 0));
        label_4->setText(QApplication::translate("MainWindow", "Z:", 0));
        minusZbutton->setText(QApplication::translate("MainWindow", "-", 0));
        plusZbutton->setText(QApplication::translate("MainWindow", "+", 0));
        label_7->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261:", 0));
        plusScalebutton->setText(QApplication::translate("MainWindow", "+", 0));
        minusScalebutton->setText(QApplication::translate("MainWindow", "-", 0));
        label_23->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\320\265\320\271", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\203\320\267\320\260", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", 0));
        MoveModelUpbutton->setText(QApplication::translate("MainWindow", "/\\", 0));
        MoveModelRightbutton->setText(QApplication::translate("MainWindow", ">", 0));
        MoveModelForwardbutton->setText(QApplication::translate("MainWindow", "o", 0));
        MovesModelBackwardbutton->setText(QApplication::translate("MainWindow", "+", 0));
        MoveModelLeftbutton->setText(QApplication::translate("MainWindow", "<", 0));
        MoveModelDownbutton->setText(QApplication::translate("MainWindow", "\\/", 0));
        label_24->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\264\320\260: ", 0));
        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\262\320\270\320\266\320\265\320\275\320\270\320\265:", 0));
        label_13->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 (max = 110% \320\276\321\202 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\217)", 0));
        label_21->setText(QApplication::translate("MainWindow", "\320\232\320\260\321\202\320\276\320\264:", 0));
        label_22->setText(QApplication::translate("MainWindow", "\320\220\320\275\320\276\320\264:", 0));
        radioButton->setText(QApplication::translate("MainWindow", "\320\220\320\272\321\202\320\270\320\262\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\220\320\272\321\202\320\270\320\262\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\217\320\264\320\276\320\272 \321\200\320\260\320\267\320\261\320\270\320\265\320\275\320\270\321\217 (max = 8)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
