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

void Scene::normalizationVertex(vector<Vertex> _vertex, float min, float max){
    /* Процесс нормализации */
    /* Использовать только на сцене для показа */
    vector<Vertex> newVertex;
    int tmpX, tmpY, tmpZ;
    int maxX, maxY, maxZ, minZ;

    maxX = getMax(_vertex, xAx);
    maxY = getMax(_vertex, yAx);
    maxZ = getMax(_vertex, zAx);
    minZ = getMin(_vertex, zAx);

    for(int i = 0; i < (int)_vertex.size(); i++){
        tmpX = min + (_vertex[i].getPosition().x - MIN_X) * (max - min) / (maxX - MIN_X);
        tmpY = min + (_vertex[i].getPosition().y - MIN_Y) * (max - min) / (maxY - MIN_Y);
        tmpZ = min + (_vertex[i].getPosition().z - minZ) * (max - min) / (maxZ - minZ);
        Vertex tmp(tmpX, tmpY, tmpZ);
        newVertex.push_back(tmp);
    }
    _figures.clear();
    _figures.push_back(newVertex);
}

int Scene::getMax(vector<Vertex> _vertex, Axis ax){
    int resMax = 0;
    switch (ax){
    case xAx:
        resMax = getMaxX(_vertex);
        break;
    case yAx:
        resMax = getMaxY(_vertex);
        break;
    case zAx:
        resMax = getMaxZ(_vertex);
        break;
    }
    return resMax;
}

int Scene::getMin(vector<Vertex> _vertex, Axis ax){
    int resMin = 0;
    switch (ax){
    case xAx:
        resMin = getMinX(_vertex);
        break;
    case yAx:
        resMin = getMinY(_vertex);
        break;
    case zAx:
        resMin = getMinZ(_vertex);
        break;
    }
    return resMin;
}

int Scene::getMaxX(vector<Vertex> _vertex){
    int resMaxCount = _vertex[0].getPosition().x;
    for (int i = 1 ; i < (int)_vertex.size(); i++){
        if (_vertex[i].getPosition().x > resMaxCount)
            resMaxCount = _vertex[i].getPosition().x;
    }
    return resMaxCount;
}

int Scene::getMaxY(vector<Vertex> _vertex){
    int resMaxCount = _vertex[0].getPosition().y;
    for (int i = 1 ; i < (int)_vertex.size(); i++){
        if (_vertex[i].getPosition().y > resMaxCount)
            resMaxCount = _vertex[i].getPosition().y;
    }
    return resMaxCount;
}

int Scene::getMaxZ(vector<Vertex> _vertex){
    int resMaxCount = _vertex[0].getPosition().z;
    for (int i = 1 ; i < (int)_vertex.size(); i++) {
        if (_vertex[i].getPosition().z > resMaxCount)
            resMaxCount = _vertex[i].getPosition().z;
    }
    return resMaxCount;
}

int Scene::getMinX(vector<Vertex> _vertex){
    int resMinCount = _vertex[0].getPosition().x;
        for (int i = 1 ; i < (int)_vertex.size(); i++) {
            if (_vertex[i].getPosition().x < resMinCount)
                resMinCount = _vertex[i].getPosition().x;
        }
        return resMinCount;
}

int Scene::getMinY(vector<Vertex> _vertex){
    int resMinCount = _vertex[0].getPosition().y;
        for(int i = 1 ; i < (int)_vertex.size(); i++){
            if(_vertex[i].getPosition().y < resMinCount)
                resMinCount = _vertex[i].getPosition().y;
        }
        return resMinCount;
}

int Scene::getMinZ(vector<Vertex> _vertex){
    int resMinCount = _vertex[0].getPosition().z;
        for (int i = 1; i < (int)_vertex.size(); i++){
            if (_vertex[i].getPosition().z < resMinCount)
                resMinCount = _vertex[i].getPosition().z;
        }
        return resMinCount;
}
