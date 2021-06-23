#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include "sceneobject.h"
#include "edge.h"
#include "vertex.h"
using namespace std;

class Figure : public SceneObject{
private:
    vector<Vertex> vertices;
    vector<Edge> edges;
public:
    Figure();
    Figure(vector<Vertex> _vert);
    vector<Vertex> getVertices();
    vector<Edge> getEdges();

    void virtual transform(TransformMatrix _transformMatrix) override;
};

#endif
