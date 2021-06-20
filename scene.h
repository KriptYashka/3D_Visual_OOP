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
    double getMinZ(vector<Vertex> _vertex);
    double getMinY(vector<Vertex> _vertex);
    double getMinX(vector<Vertex> _vertex);
    double getMaxZ(vector<Vertex> _vertex);
    double getMaxY(vector<Vertex> _vertex);
    double getMaxX(vector<Vertex> _vertex);
    double getMin(vector<Vertex> _vertex, Axis ax);
    double getMax(vector<Vertex> _vertex, Axis ax);
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
