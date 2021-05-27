#include "filereader.h"

FileReader::FileReader()
{

}

Scene FileReader::readScene(std::string path, NormalizationParameters _normalizationParameters)
{
    vector<Vertex> _vertex;
    int tmpX, tmpY, tmpZ;
    std::ifstream file;
    file.open(path);
    std::string str;
    if(!file.is_open())
        return Scene();

    char* cStr= new char[255];
    char *currenValue = new char[255];

    for(int i = 0; getline(file, str); i += _normalizationParameters.dyStep)
    {
        strcpy(cStr,str.c_str());
        currenValue = strtok (cStr,",");
        for(int j = 0; currenValue != NULL; j += _normalizationParameters.dxStep)
        {
            tmpZ=std::atoi(currenValue);
            tmpX=(j+1);
            tmpY=(i+1);
            Vertex tmp(tmpX, tmpY, tmpZ);  //создаем еще одну вершину из считанных координат
            _vertex.push_back(tmp);        //помещаем в наш массив вершнин
            currenValue = strtok (NULL,",");
        }
    }
    delete [] cStr;

    _vertex = normalizationVertex(_vertex, _normalizationParameters.min, _normalizationParameters.max);
    vector<Figure> _figure;
    _figure.push_back(_vertex);
    Scene _scene = Scene(_figure);

    return _scene;
}

vector<Vertex> FileReader::normalizationVertex(vector<Vertex> _vertex, float min, float max)
{
    vector<Vertex> newVertex;
    int tmpX, tmpY, tmpZ;
    int maxX, maxY, maxZ, minZ;

    maxX = getMax(_vertex, xAx);
    maxY = getMax(_vertex, yAx);
    maxZ = getMax(_vertex, zAx);
    minZ = getMin(_vertex, zAx);

    for(int i = 0; i < (int)_vertex.size(); i++)
    {
        tmpX = min + (_vertex[i].getPosition().x - MIN_X)*(max - min)/(maxX - MIN_X);
        tmpY = min + (_vertex[i].getPosition().y - MIN_Y)*(max - min)/(maxY - MIN_Y);
        tmpZ = min + (_vertex[i].getPosition().z - minZ)*(max - min)/(maxZ - minZ);
        Vertex tmp(tmpX, tmpY, tmpZ);
        newVertex.push_back(tmp);
    }
    return newVertex;
}

int FileReader::getMax(vector<Vertex> _vertex, Axis ax)
{
    int resMax = 0;
    switch (ax)
    {
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

int FileReader::getMin(vector<Vertex> _vertex, Axis ax)
{
    int resMin = 0;
    switch (ax)
    {
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

int FileReader::getMaxX(vector<Vertex> _vertex)
{
    int resMaxCount = _vertex[0].getPosition().x;
    for(int i = 1 ;i < (int)_vertex.size();i++)
    {
        if(_vertex[i].getPosition().x > resMaxCount)
            resMaxCount = _vertex[i].getPosition().x;
    }
    return resMaxCount;
}

int FileReader::getMaxY(vector<Vertex> _vertex)
{
    int resMaxCount = _vertex[0].getPosition().y;
    for(int i = 1 ;i < (int)_vertex.size();i++)
    {
        if(_vertex[i].getPosition().y > resMaxCount)
            resMaxCount = _vertex[i].getPosition().y;
    }
    return resMaxCount;
}

int FileReader::getMaxZ(vector<Vertex> _vertex)
{
    int resMaxCount = _vertex[0].getPosition().z;
    for(int i = 1 ;i < (int)_vertex.size();i++)
    {
        if(_vertex[i].getPosition().z > resMaxCount)
            resMaxCount = _vertex[i].getPosition().z;
    }
    return resMaxCount;
}

int FileReader::getMinX(vector<Vertex> _vertex)
{
    int resMinCount = _vertex[0].getPosition().x;
        for(int i = 1 ;i < (int)_vertex.size();i++)
        {
            if(_vertex[i].getPosition().x < resMinCount)
                resMinCount = _vertex[i].getPosition().x;
        }
        return resMinCount;
}

int FileReader::getMinY(vector<Vertex> _vertex)
{
    int resMinCount = _vertex[0].getPosition().y;
        for(int i = 1 ;i < (int)_vertex.size();i++)
        {
            if(_vertex[i].getPosition().y < resMinCount)
                resMinCount = _vertex[i].getPosition().y;
        }
        return resMinCount;
}

int FileReader::getMinZ(vector<Vertex> _vertex)
{

    int resMinCount = _vertex[0].getPosition().z;
        for(int i = 1 ;i < (int)_vertex.size();i++)
        {
            if(_vertex[i].getPosition().z < resMinCount)
                resMinCount = _vertex[i].getPosition().z;
        }
        return resMinCount;
}
