#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include "figure.h"
#include "transformmatrix.h"

#include "normalizationparameters.h"
#include "axis.h"

#define MIN_X 0
#define MIN_Y 0

class Scene{
private:
    vector<Figure> _figures;
    int getMinZ(vector<Vertex> _vertex);
    int getMinY(vector<Vertex> _vertex);
    int getMinX(vector<Vertex> _vertex);
    int getMaxZ(vector<Vertex> _vertex);
    int getMaxY(vector<Vertex> _vertex);
    int getMaxX(vector<Vertex> _vertex);
    int getMin(vector<Vertex> _vertex, Axis ax);
    int getMax(vector<Vertex> _vertex, Axis ax);
public:
    Scene();
    Scene(vector<Figure> _figures);
    vector<Figure> getFigures();
    Scene& operator += (Scene _scene);
    void transformFigures(TransformMatrix _transformmatrix);
    void clear();
    void normalizationVertex(vector<Vertex> _vertex, NormalizationParameters params);
};

#endif
