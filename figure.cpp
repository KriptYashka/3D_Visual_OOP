#include "figure.h"

Figure::Figure():SceneObject(){}

Figure::Figure(vector<Vertex> _vert){
    vertices = _vert;
}

vector<Vertex> Figure::getVertices(){
    return vertices;
}

vector<Edge> Figure::getEdges(){
    return edges;
}

void Figure::transform(TransformMatrix _transformMatrix){
    for(int i = 0; i < (int)vertices.size(); i++)
        vertices[i].transform(_transformMatrix);
}
