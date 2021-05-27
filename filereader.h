#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "basefilereader.h"
#include "normalizationparameters.h"
#include "scene.h"
#include "axis.h"

#define MIN_X 0
#define MIN_Y 0

class FileReader : public BaseFileReader
{
public:
    FileReader();

    virtual Scene readScene(string path, NormalizationParameters _normalizationParameters) override;

    vector<Vertex> normalizationVertex(vector<Vertex> _vertex, float min, float max);

    int getMax(vector<Vertex> _vertex, Axis ax);
    int getMin(vector<Vertex> _vertex, Axis ax);

    int getMaxX(vector<Vertex> _vertex);
    int getMaxY(vector<Vertex> _vertex);
    int getMaxZ(vector<Vertex> _vertex);
    int getMinX(vector<Vertex> _vertex);
    int getMinY(vector<Vertex> _vertex);
    int getMinZ(vector<Vertex> _vertex);
};

#endif // FILEREADER_H
