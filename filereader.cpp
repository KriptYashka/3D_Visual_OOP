#include "filereader.h"
using namespace std;
FileReader::FileReader(){}

Scene FileReader::readScene(string path, NormalizationParameters _normalizationParameters){
    vector<Vertex> _vertex;
    double tmpX, tmpY, tmpZ;
    ifstream file;
    file.open(path);
    string str;
    if (!file.is_open())
        return Scene();

    char* charWord = new char[255];
    char *currenValue = new char[255];

    for (int i = 1; getline(file, str); i += _normalizationParameters.dyStep){
        strcpy(charWord, str.c_str());
        currenValue = strtok (charWord,",");
        for(int j = 1; currenValue != NULL; j += _normalizationParameters.dxStep){
            tmpZ = atoi(currenValue);
            tmpX = j;
            tmpY = i;
            Vertex tmp(tmpX, tmpY, tmpZ);  //создаем еще одну вершину из считанных координат
            _vertex.push_back(tmp);        //помещаем в наш массив вершнин
            currenValue = strtok (NULL,",");
        }
    }
    delete [] charWord;

    Scene _scene = Scene();
    _scene.normalizationVertex(_vertex, _normalizationParameters);

    return _scene;
}
