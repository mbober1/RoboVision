#include "scene.hpp"

float degToPi(float deg) { return deg * (M_PI/180); }


Scene::Scene(QWidget *parent) : 
QWidget(parent), x(0), y(0), z(0)
{
    // window
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    container->setMinimumSize(QSize(400, 400));
    view->defaultFrameGraph()->setClearColor(QColor(53, 53, 53));


    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    QUrl data = QUrl::fromLocalFile("/home/mbober/Documents/RoboVision/chassis.obj");


    // camera
    camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 250.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));  
    
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(camera);  


    // light
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("red");
    light->setIntensity(1);
    lightEntity->addComponent(light);

    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(60, 0, 40.0f));
    lightEntity->addComponent(lightTransform);


    // object
    this->robot = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QSceneLoader *loader = new Qt3DRender::QSceneLoader(rootEntity);
    loader->setSource(data);
    this->robot->addComponent(loader);

    this->rotate(degToPi(10), degToPi(150), degToPi(0));

    view->setRootEntity(rootEntity);
}

void Scene::rotate(float x, float y, float z) {
    this->x += x;
    this->y += y;
    this->z += z;
    auto *transform = new Qt3DCore::QTransform();
    QMatrix4x4 matrix;
    QMatrix4x4 matrix_x(1, 0, 0, 0, 0, cos(this->x), -sin(this->x), 0 , 0, sin(this->x), cos(this->x), 0, 0, 0, 0, 1);
    QMatrix4x4 matrix_y(cos(this->y), 0, sin(this->y), 0, 0, 1, 0, 0, -sin(this->y), 0, cos(this->y), 0, 0, 0, 0, 1);
    QMatrix4x4 matrix_z(cos(this->z), -sin(this->z), 0, 0, sin(this->z), cos(this->z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    matrix = matrix_x * matrix_y * matrix_z;
    transform->setMatrix(matrix);
    this->robot->addComponent(transform);
}
