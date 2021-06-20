#ifndef VERTEX_H
#define VERTEX_H

#include "sceneobject.h"
#include "point.h"
#include "sceneobject.h"

class Vertex : public SceneObject{
private:
    Point _position;
public:
    Vertex();
    Vertex(double _x, double _y, double _z);
    Point getPosition();
    void transform(TransformMatrix _transformMatrix) override;
};

#endif // VERTEX_H
