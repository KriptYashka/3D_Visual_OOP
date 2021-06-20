#include "vertex.h"

Vertex::Vertex() : SceneObject(){}

Vertex::Vertex(double _x, double _y, double _z){
    _position.x = _x;
    _position.y = _y;
    _position.z = _z;
}

Point Vertex::getPosition(){
    return _position;
}

void Vertex::transform(TransformMatrix _transformMatrix){
    _position = _transformMatrix.TransformPoint(_position);
}
