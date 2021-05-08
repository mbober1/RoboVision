#include "scene.hpp"


Scene::Scene(QWidget *parent) : 
QWidget(parent)
{
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    container->setMinimumSize(QSize(400, 400));

    view->defaultFrameGraph()->setClearColor(QColor(49, 54, 59));

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    QUrl data = QUrl::fromLocalFile("/home/mbober/Documents/RoboVision/Model.obj");

    camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));    

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(0.8f);
    lightEntity->addComponent(light);

    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(60, 0, 40.0f));
    lightEntity->addComponent(lightTransform);

    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(camera);


    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(255, 0, 0));

    Qt3DCore::QEntity *robot = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QMesh *robotMesh = new Qt3DRender::QMesh;
    robotMesh->setSource(data);
    robot->addComponent(robotMesh);
    robot->addComponent(material);

    // Sphere
    Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
    sphereMesh->setRadius(3);
    sphereEntity->addComponent(sphereMesh);
    sphereEntity->addComponent(material);


    view->setRootEntity(rootEntity);
    // view->show();
}