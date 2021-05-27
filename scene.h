#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include "figure.h"
#include "transformmatrix.h"
using std::string;
using std::vector;

class Scene
{
private:
    vector<Figure> _figures;
public:
    Scene();
    Scene(vector<Figure> _figures);
    vector<Figure> getFigures();
    Scene& operator += (Scene _scene);
    void transformFigures(TransformMatrix _transformmatrix);
};

#endif // SCENE_H
