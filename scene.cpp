#include "scene.h"

Scene::Scene(){}

Scene::Scene(vector<Figure> figures){
    _figures = figures;
}

void Scene::clear(){
    _figures.clear();
}

vector<Figure> Scene::getFigures(){
    return _figures;
}

Scene &Scene::operator +=(Scene _scene){
    for (int i = 0; i < (int)_scene.getFigures().size(); i++)
    _figures.push_back(_scene._figures[i]);
    return *this;
}

void Scene::transformFigures(TransformMatrix _transformmatrix){
    for(int i = 0; i < (int)_figures.size(); i++)
        _figures[i].transform(_transformmatrix);
}
