#ifndef FACADE_H
#define FACADE_H
#include <iostream>
#include "facadeoperationresult.h"
#include "normalizationparameters.h"
#include "basefilereader.h"
#include "scene.h"
#include "scenedrawerbase.h"
#include "transformmatrixbuilder.h"
#include "filereader.h"
#include "qtscenedrawer.h"

class Facade{
private:
    BaseFileReader* fileReader;
    SceneDrawerBase* sceneDrawer;
    NormalizationParameters _normPar;

public:
    Scene picture;
    Scene filedata;
    Facade(QWidget*);

    FacadeOperationResult drawScene();
    FacadeOperationResult loadScene(string path, NormalizationParameters _normalizationParameters);
    FacadeOperationResult offsetScene(float x, float y, float z);
    FacadeOperationResult rotateScene(float x, float y, float z);
    FacadeOperationResult scaleScene(float x, float y, float z);
    FacadeOperationResult normalizeScene(NormalizationParameters _normalizationParameters);
};

#endif // FACADE_H
