#include "facade.h"
using namespace std;

Facade::Facade(QWidget* q){
    fileReader = new FileReader();
    sceneDrawer = new QtSceneDrawer(q);
}

FacadeOperationResult Facade::drawScene(){
    sceneDrawer->drawScene(picture);
    return FacadeOperationResult();
}

FacadeOperationResult Facade::loadScene(string path, NormalizationParameters _normalizationParameters){
    /* Загрузка сцены */
    FacadeOperationResult response("Нельзя открыть файл!", false);
    picture.clear();
    picture = fileReader->readScene(path, _normalizationParameters);
    filedata = picture;
    if (!picture.isEmpty()){
        response.setMessage("Файл успешно загружен!");
        response.setIsSuccess(true);
    }
    return response;
}

FacadeOperationResult Facade::offsetScene(double x, double y, double z){
    /* Перемещение сцены */
    FacadeOperationResult response("Empty file!",false);
    if (!filedata.isEmpty()){
        filedata.transformFigures(TransformMatrixBuilder::createMoveMatrix(x,y,z));
        picture = filedata;
        response.setIsSuccess(true);
        response.setMessage("Сцена передвинута!");
    }
    return response;
}

FacadeOperationResult Facade::rotateScene(double x, double y, double z){
    /* Поворот сцены */
    FacadeOperationResult response("Пустой файл!",false);
    if (!filedata.isEmpty()){
        filedata.transformFigures(TransformMatrixBuilder::createRotationMatrix(x,y,z));
        picture = filedata;
        response.setIsSuccess(true);
        response.setMessage("Сцена повернута!");
    }
    return response;
}

FacadeOperationResult Facade::scaleScene(double x, double y, double z){
    /* Масштабирование сцены */
    FacadeOperationResult response("Пустой файл!",false);
    if (!filedata.isEmpty()){
        filedata.transformFigures(TransformMatrixBuilder::createScaleMatrix(x,y,z));
        picture = filedata;
        response.setIsSuccess(true);
        response.setMessage("Сцена масштабирована!");
    }
    return response;
}

FacadeOperationResult Facade::normalizeScene(NormalizationParameters params){
    /* Нормализация сцены */
    FacadeOperationResult response("Пустой файл!",false);
    if (!filedata.isEmpty()){
        picture.normalizationVertex(filedata.getFigures().at(0).getVertices(), params);
        response.setIsSuccess(true);
        response.setMessage("Сцена нормализованна!");
    }
    return response;
}
