#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H
#include "transformmatrix.h"

class SceneObject
{
public:
    SceneObject();
    virtual void transform(TransformMatrix _traseformMatrix);
};

#endif // SCENEOBJECT_H
