#ifndef VERTEX_H
#define VERTEX_H

#include "sceneobject.h"
#include "point.h"
#include "sceneobject.h"

class Vertex : public SceneObject{
private:
    Point point;
public:
    Vertex();
    Vertex(double x, double y, double z);
    Point getPosition();
    void transform(TransformMatrix _transformMatrix) override;
};

#endif // VERTEX_H
