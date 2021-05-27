#include "facade.h"
using namespace std;

Facade::Facade(QWidget* q){
    _fileReader = new FileReader();
    _scenDrawer = new QtSceneDrawer(q);
}

FacadeOperationResult Facade::drawScene(){
    _scenDrawer->drawScene(_scene);
    return FacadeOperationResult();
}

FacadeOperationResult Facade::loadScene(string path, NormalizationParameters _normalizationParameters){
    FacadeOperationResult _operationRes("File did not open!", false);
    _scene.clear();
    _scene += _fileReader->readScene(path, _normalizationParameters);
    if (_scene.getFigures().size() != 0){
        _operationRes.setMessage("File is successful open!");
        _operationRes.setIsSuccess(true);
    }
    return _operationRes;
}

FacadeOperationResult Facade::moveScene(float x, float y, float z){
    FacadeOperationResult _operationRes("Empty file!",false);
    if(_scene.getFigures().size() != 0)
    {
        _scene.transformFigures(TransformMatrixBuilder::createMoveMatrix(x,y,z));
        _operationRes.setIsSuccess(true);
        _operationRes.setMessage("File successful moving!");
    }
    return _operationRes;
}

FacadeOperationResult Facade::rotateScene(float x, float y, float z){
    FacadeOperationResult _operationRes("Empty file!",false);
    if(_scene.getFigures().size() != 0){
        _scene.transformFigures(TransformMatrixBuilder::createRotationMatrix(x,y,z));
        _operationRes.setIsSuccess(true);
        _operationRes.setMessage("File successful rotate!");
    }
    return _operationRes;
}

FacadeOperationResult Facade::scaleScene(float x, float y, float z){
    FacadeOperationResult _operationRes("Empty file!",false);
    if(_scene.getFigures().size() != 0){
        _scene.transformFigures(TransformMatrixBuilder::createScaleMatrix(x,y,z));
        _operationRes.setIsSuccess(true);
        _operationRes.setMessage("File successful scale!");
    }
    return _operationRes;
}
