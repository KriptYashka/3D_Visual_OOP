#include "vertex.h"

Vertex::Vertex() : SceneObject(){}

Vertex::Vertex(double _x, double _y, double _z){
    point.x = _x;
    point.y = _y;
    point.z = _z;
}

Point Vertex::getPosition(){
    return point;
}

void Vertex::transform(TransformMatrix _transformMatrix){
    point = _transformMatrix.TransformPoint(point);
}
