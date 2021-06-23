#ifndef BASEFILEREADER_H
#define BASEFILEREADER_H
#include <iostream>
#include "normalizationparameters.h"
#include "scene.h"

using std::string;

class BaseFileReader{
public:
    BaseFileReader();
    virtual Scene readScene(string path, NormalizationParameters _normalizationParameters);
};

#endif // BASEFILEREADER_H
