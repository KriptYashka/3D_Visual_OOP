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

void Scene::normalizationVertex(vector<Vertex> _vertex, NormalizationParameters params){
    /* Процесс нормализации */
    /* Использовать только на сцене для показа */
    vector<Vertex> newVertex;
    double tmpX, tmpY, tmpZ;
    double maxX, maxY, maxZ, minZ, minX, minY;

    maxX = getMax(_vertex, xAx);
    maxY = getMax(_vertex, yAx);
    maxZ = getMax(_vertex, zAx);
    minX = getMin(_vertex, xAx);
    minY = getMin(_vertex, yAx);
    minZ = getMin(_vertex, zAx);

    double min = params.min;
    double max = params.max;

    for(int i = 0; i < (int)_vertex.size(); i++){
        tmpX = (min + (_vertex[i].getPosition().x - minX) * (max - min) / (maxX - minX)) * params.dxStep;
        tmpY = (min + (_vertex[i].getPosition().y - minY) * (max - min) / (maxY - minY)) * params.dyStep;
        tmpZ = (min + (_vertex[i].getPosition().z - minZ) * (max - min) / (maxZ - minZ));
        Vertex tmp(tmpX, tmpY, tmpZ);
        newVertex.push_back(tmp);
    }
    _figures.clear();
    _figures.push_back(newVertex);
}

double Scene::getMax(vector<Vertex> _vertex, Axis ax){
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

double Scene::getMin(vector<Vertex> _vertex, Axis ax){
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

double Scene::getMaxX(vector<Vertex> _vertex){
    int resMaxCount = _vertex[0].getPosition().x;
    for (int i = 1 ; i < (int)_vertex.size(); i++){
        if (_vertex[i].getPosition().x > resMaxCount)
            resMaxCount = _vertex[i].getPosition().x;
    }
    return resMaxCount;
}

double Scene::getMaxY(vector<Vertex> _vertex){
    int resMaxCount = _vertex[0].getPosition().y;
    for (int i = 1 ; i < (int)_vertex.size(); i++){
        if (_vertex[i].getPosition().y > resMaxCount)
            resMaxCount = _vertex[i].getPosition().y;
    }
    return resMaxCount;
}

double Scene::getMaxZ(vector<Vertex> _vertex){
    int resMaxCount = _vertex[0].getPosition().z;
    for (int i = 1 ; i < (int)_vertex.size(); i++) {
        if (_vertex[i].getPosition().z > resMaxCount)
            resMaxCount = _vertex[i].getPosition().z;
    }
    return resMaxCount;
}

double Scene::getMinX(vector<Vertex> _vertex){
    int resMinCount = _vertex[0].getPosition().x;
        for (int i = 1 ; i < (int)_vertex.size(); i++) {
            if (_vertex[i].getPosition().x < resMinCount)
                resMinCount = _vertex[i].getPosition().x;
        }
        return resMinCount;
}

double Scene::getMinY(vector<Vertex> _vertex){
    int resMinCount = _vertex[0].getPosition().y;
        for(int i = 1 ; i < (int)_vertex.size(); i++){
            if(_vertex[i].getPosition().y < resMinCount)
                resMinCount = _vertex[i].getPosition().y;
        }
        return resMinCount;
}

double Scene::getMinZ(vector<Vertex> _vertex){
    int resMinCount = _vertex[0].getPosition().z;
        for (int i = 1; i < (int)_vertex.size(); i++){
            if (_vertex[i].getPosition().z < resMinCount)
                resMinCount = _vertex[i].getPosition().z;
        }
        return resMinCount;
}
