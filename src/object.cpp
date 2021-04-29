#include "object.hpp"

Object::Object(Qt3DCore::QNode *parent)
    : Qt3DCore::QEntity(parent)
    , local_transform(new Qt3DCore::QTransform()),local_mesh(new Qt3DRender::QMesh), local_material(new Qt3DExtras::QPhongMaterial(parent)), local_torusMesh(new Qt3DExtras::QTorusMesh), local_loader(new Qt3DRender::QSceneLoader(parent))
{
    addComponent(local_transform);
    //addComponent(local_mesh);
    addComponent(local_material);
    //addComponent(local_torusMesh);
    addComponent(local_material);
    addComponent(local_loader);
    qDebug()<<parent;
}

Qt3DRender::QSceneLoader *Object::loader()
{
    return local_loader;
}
