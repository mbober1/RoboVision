/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionQuit;
    QAction *actionGitHub;
    QAction *actionAbout;
    QAction *actionDisconnect;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *labelGamepadStatus;
    QProgressBar *progressBarBattery;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBarObstacle;
    QLCDNumber *lcdNumberPing;
    QLabel *label_5;
    QLabel *label_6;
    QOpenGLWidget *openGLWidget;
    QOpenGLWidget *openGLWidget_2;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLCDNumber *lcdNumberSpeed;
    QLabel *labelConnectionStatus;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(300, 0));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionGitHub = new QAction(MainWindow);
        actionGitHub->setObjectName(QString::fromUtf8("actionGitHub"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionDisconnect->setEnabled(false);
        actionDisconnect->setVisible(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        labelGamepadStatus = new QLabel(centralwidget);
        labelGamepadStatus->setObjectName(QString::fromUtf8("labelGamepadStatus"));

        gridLayout->addWidget(labelGamepadStatus, 7, 0, 1, 2);

        progressBarBattery = new QProgressBar(centralwidget);
        progressBarBattery->setObjectName(QString::fromUtf8("progressBarBattery"));
        progressBarBattery->setValue(0);

        gridLayout->addWidget(progressBarBattery, 6, 2, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 4, 1, 1);

        progressBarObstacle = new QProgressBar(centralwidget);
        progressBarObstacle->setObjectName(QString::fromUtf8("progressBarObstacle"));
        progressBarObstacle->setValue(0);

        gridLayout->addWidget(progressBarObstacle, 4, 3, 1, 3);

        lcdNumberPing = new QLCDNumber(centralwidget);
        lcdNumberPing->setObjectName(QString::fromUtf8("lcdNumberPing"));
        lcdNumberPing->setFrameShape(QFrame::NoFrame);
        lcdNumberPing->setLineWidth(1);
        lcdNumberPing->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdNumberPing, 4, 7, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 8, 1, 1);

        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 1, 0, 2, 6);

        openGLWidget_2 = new QOpenGLWidget(centralwidget);
        openGLWidget_2->setObjectName(QString::fromUtf8("openGLWidget_2"));

        gridLayout->addWidget(openGLWidget_2, 1, 6, 2, 3);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 8, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 6, 6, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 4, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 7, 1, 1);

        lcdNumberSpeed = new QLCDNumber(centralwidget);
        lcdNumberSpeed->setObjectName(QString::fromUtf8("lcdNumberSpeed"));
        lcdNumberSpeed->setFrameShape(QFrame::NoFrame);
        lcdNumberSpeed->setSmallDecimalPoint(false);
        lcdNumberSpeed->setDigitCount(5);
        lcdNumberSpeed->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberSpeed->setProperty("value", QVariant(0.000000000000000));

        gridLayout->addWidget(lcdNumberSpeed, 6, 7, 1, 1);

        labelConnectionStatus = new QLabel(centralwidget);
        labelConnectionStatus->setObjectName(QString::fromUtf8("labelConnectionStatus"));
        labelConnectionStatus->setMinimumSize(QSize(110, 0));
        labelConnectionStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelConnectionStatus, 7, 6, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 34));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QString::fromUtf8("menuConnection"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuConnection->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuConnection->addAction(actionConnect);
        menuConnection->addAction(actionDisconnect);
        menuConnection->addSeparator();
        menuConnection->addAction(actionQuit);
        menuHelp->addAction(actionGitHub);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionGitHub->setText(QCoreApplication::translate("MainWindow", "GitHub", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About this program", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Battery", nullptr));
        labelGamepadStatus->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Obstacle distance", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "km/h", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Speedometer", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ping", nullptr));
        labelConnectionStatus->setText(QCoreApplication::translate("MainWindow", "DISCONNECTED", nullptr));
        menuConnection->setTitle(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
