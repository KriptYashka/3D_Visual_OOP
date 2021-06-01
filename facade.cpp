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
    FacadeOperationResult _operationRes("Нельзя открыть файл!", false);
    _scenedata.clear();
    _scenedata += _fileReader->readScene(path, _normalizationParameters);
    _scene = _scenedata;
    if (_scenedata.getFigures().size() != 0){
        _operationRes.setMessage("Файл успешно прочитан!");
        _operationRes.setSuccess(true);
    }
    return _operationRes;
}

FacadeOperationResult Facade::moveScene(float x, float y, float z){
    FacadeOperationResult _operationRes("Нет фигур!",false);
    if (_scene.getFigures().size() != 0){
        _scene.transformFigures(TransformMatrixBuilder::createMoveMatrix(x,y,z));
        _operationRes.setSuccess(true);
        _operationRes.setMessage("Объект перемещен");
    }
    return _operationRes;
}

FacadeOperationResult Facade::rotateScene(float x, float y, float z){
    FacadeOperationResult _operationRes("Empty file!",false);
    if(_scene.getFigures().size() != 0){
        _scene.transformFigures(TransformMatrixBuilder::createRotationMatrix(x,y,z));
        _operationRes.setSuccess(true);
        _operationRes.setMessage("File successful rotate!");
    }
    return _operationRes;
}

FacadeOperationResult Facade::scaleScene(float x, float y, float z){
    FacadeOperationResult _operationRes("Empty file!",false);
    if (_scene.getFigures().size() != 0){
        _scene.transformFigures(TransformMatrixBuilder::createScaleMatrix(x,y,z));
        _operationRes.setSuccess(true);
        _operationRes.setMessage("File successful scale!");
    }
    return _operationRes;
}

FacadeOperationResult Facade::normalizeScene(float min, float max){
    FacadeOperationResult _operationRes("Empty file!",false);
    if (_scene.getFigures().size() != 0){
        _scene.normalizationVertex(_scenedata.getFigures().at(0).getVertices(), min, max);
        _operationRes.setSuccess(true);
        _operationRes.setMessage("File successful scale!");
    }
    return _operationRes;
}
