#include "scene.hpp"


Scene::Scene(QWidget *parent) : 
QWidget(parent)
{
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    container->setMinimumSize(QSize(400, 400));
    rootEntity = new Qt3DCore::QEntity();

    camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    // Torus
    // Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(rootEntity);
    // Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
    // torusMesh->setRadius(5);
    // torusMesh->setMinorRadius(1);
    // torusMesh->setRings(100);
    // torusMesh->setSlices(20);

    // Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
    // torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    // torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    // torusEntity->addComponent(torusMesh);
    // torusEntity->addComponent(torusTransform);
    // torusEntity->addComponent(material);

    // Sphere
    Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
    sphereMesh->setRadius(3);
    sphereMesh->setGenerateTangents(true);

    Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform;

    sphereEntity->addComponent(sphereMesh);
    sphereEntity->addComponent(sphereTransform);
    sphereEntity->addComponent(material);

    this->object = new Object(this->rootEntity);
    this->object->loader()->setSource(QUrl(QString("file:/home/mbober/Documents/RoboVision/chassis.stl")));
    view->setRootEntity(rootEntity);

}


void Scene::createObject() {
    // this->object = new Object(this->rootEntity);
    // this->object->loader()->setSource(QUrl(QString("file:/home/mbober/Documents/RoboVision/chassis.stl")));
}
