#ifndef VERTEX_H
#define VERTEX_H

#include "sceneobject.h"
#include "point.h"
#include "sceneobject.h"

class Vertex : public SceneObject
{
private:
    Point _position;
public:
    Vertex();
    Vertex(int _x, int _y, int _z);
    Point getPosition();
    void transform(TransformMatrix _transformMatrix) override;
};

#endif // VERTEX_H
