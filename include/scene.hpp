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


class Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);

    Qt3DRender::QCamera *camera;
    QWidget *container;

public slots:


private:
};

#endif //SCENE_H





