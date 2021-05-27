#include "figure.h"

Figure::Figure():SceneObject()
{

}

Figure::Figure(vector<Vertex> _vert)
{
    _vertices = _vert;
}

vector<Vertex> Figure::getVertices()
{
    return _vertices;
}

vector<Edge> Figure::getEdges()
{
    return _edges;
}

void Figure::transform(TransformMatrix _transformMatrix)
{
    for(int i = 0; i < (int)_vertices.size(); i++)
        _vertices[i].transform(_transformMatrix);
}
