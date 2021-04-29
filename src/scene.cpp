#include "scene.hpp"


Scene::Scene(QWidget *parent) : 
QWidget(parent)
{
    // // Root entity
    //     rootEntity = new Qt3DCore::QEntity();

    // // Camera
    // cameraEntity = view->camera();

    // // For the Blender model:
    //     // X+ -> right
    //     // Y+ -> away
    //     // Z+ -> up
    //     cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    //     cameraEntity->setPosition(QVector3D(0, -5, 5.0f));
    //     cameraEntity->setUpVector(QVector3D(0, 0, 1));
    //     cameraEntity->setViewCenter(QVector3D(0, 0, 0));
    // // Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);//moje
    // // camController->setCamera(cameraEntity);//moje

    // Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    // // Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    // light->setColor("white");
    // light->setIntensity(1);
    // lightEntity->addComponent(light);
    // Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    // //lightTransform->setTranslation(cameraEntity->position());
    // //lightEntity->addComponent(lightTransform);
    // lightTransform->setTranslation(QVector3D(30,-100, -20));
    // lightEntity->addComponent(lightTransform);

    // this->createObject();

       // Root entity
    rootEntity = new Qt3DCore::QEntity;
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    // Torus
    Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
    torusMesh->setRadius(5);
    torusMesh->setMinorRadius(1);
    torusMesh->setRings(100);
    torusMesh->setSlices(20);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
    torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusTransform);
    torusEntity->addComponent(material);

    // Sphere
    Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
    sphereMesh->setRadius(3);
    sphereMesh->setGenerateTangents(true);

    Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform;
    // OrbitTransformController *controller = new OrbitTransformController(sphereTransform);
    // controller->setTarget(sphereTransform);
    // controller->setRadius(20.0f);

    // QPropertyAnimation *sphereRotateTransformAnimation = new QPropertyAnimation(sphereTransform);
    // sphereRotateTransformAnimation->setTargetObject(controller);
    // sphereRotateTransformAnimation->setPropertyName("angle");
    // sphereRotateTransformAnimation->setStartValue(QVariant::fromValue(0));
    // sphereRotateTransformAnimation->setEndValue(QVariant::fromValue(360));
    // sphereRotateTransformAnimation->setDuration(10000);
    // sphereRotateTransformAnimation->setLoopCount(-1);
    // sphereRotateTransformAnimation->start();

    sphereEntity->addComponent(sphereMesh);
    sphereEntity->addComponent(sphereTransform);
    sphereEntity->addComponent(material);

    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    view->setRootEntity(rootEntity);
    view->show();
}


void Scene::createObject() {
    // this->object = new Object(this->rootEntity);
    // this->object->loader()->setSource(QUrl(QString("file:/home/mbober/Documents/RoboVision/chassis.stl")));
}
