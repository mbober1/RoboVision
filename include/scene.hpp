#pragma once
#ifndef SCENE_H
#define SCENE_H


#include <QWidget>
#include <QGuiApplication>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender>
#include <Qt3DExtras>

#include <QPropertyAnimation>

#include "qt3dwindow.h"
#include <math.h>


/*!
*   \file 
*   \brief The file contains the 3D scene class.
*/


/**
    @brief 3D scene class
*/
class Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);

    Qt3DRender::QCamera *camera;
    QWidget *container;
    Qt3DCore::QEntity *robot;

public slots:
    void rotate(float x, float y, float z);
    void resetPosition();

private:
    float x, y, z;
};

#endif //SCENE_H





