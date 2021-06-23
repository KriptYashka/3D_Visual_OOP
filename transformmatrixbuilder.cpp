#include "transformmatrixbuilder.h"

TransformMatrixBuilder::TransformMatrixBuilder(){}

TransformMatrix TransformMatrixBuilder::createRotationMatrix(double x, double y, double z){
    /* Возвращает новую матрицу с новыми позициями точками на сцене, с учётом поворота осей */
    double _x = x*M_PI/180.0;
    double _y = y*M_PI/180.0;
    double _z = z*M_PI/180.0;
    /*
    x, y, z, scale
    0  0  0  0 x
    0  0  0  0 y
    0  0  0  0 z
    0  0  0  0 scale
    */

    double matrixRotX[4][4] = {{1,0,0,0},
                                       {0,double(cos(_x)),double(-sin(_x)),0},
                                       {0,double(sin(_x)),double(cos(_x)),0},
                                       {0,0,0,1}
                                     };
    double matrixRotY[4][4] = { {double(cos(_y)),0,double(sin(_y)),0},
                                        {0,1,0,0},
                                        {double(-sin(_y)),0,double(cos(_y)),0},
                                        {0,0,0,1}
                                      };
    double matrixRotZ[4][4] = { {double(cos(_z)),double(-sin(_z)),0,0},
                                        {double(sin(_z)),double(cos(_z)),0,0},
                                        {0,0,1,0},
                                        {0,0,0,1}
                                      };
    TransformMatrix _trasfomrMatrixRotX(matrixRotX);
    TransformMatrix _trasfomrMatrixRotY(matrixRotY);
    TransformMatrix _trasfomrMatrixRotZ(matrixRotZ);

    return  _trasfomrMatrixRotX * _trasfomrMatrixRotY * _trasfomrMatrixRotZ;
}

TransformMatrix TransformMatrixBuilder::createMoveMatrix(double x, double y, double z){
    /* Перемещение матрицы */
    double matrixMove[4][4] = { {1,0,0,0},
                                        {0,1,0,0},
                                        {0,0,1,0},
                                        {x,y,z,1}
                                      };
    TransformMatrix _transfomrMatrixMove(matrixMove);
    return _transfomrMatrixMove;
}

TransformMatrix TransformMatrixBuilder::createScaleMatrix(double x, double y, double z){
    /* Масштабирование */
    double matrixScale[4][4] = { {x,0,0,0},
                                         {0,y,0,0},
                                         {0,0,z,0},
                                         {0,0,0,1}
                                      };
    TransformMatrix _transfomrMatrixScale(matrixScale);
    return _transfomrMatrixScale;
}
