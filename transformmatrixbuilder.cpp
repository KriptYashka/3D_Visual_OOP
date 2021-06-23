#include "transformmatrixbuilder.h"

TransformMatrixBuilder::TransformMatrixBuilder(){}

TransformMatrix TransformMatrixBuilder::createRotationMatrix(float x, float y, float z){
    /* Возвращает новую матрицу с новыми позициями точками на сцене, с учётом поворота осей */
    float _x = x*M_PI/180.0;
    float _y = y*M_PI/180.0;
    float _z = z*M_PI/180.0;
    /*
    x, y, z, scale
    0  0  0  0 x
    0  0  0  0 y
    0  0  0  0 z
    0  0  0  0 scale
    */

    float matrixRotX[4][4] = {{1,0,0,0},
                                       {0,float(cos(_x)),float(-sin(_x)),0},
                                       {0,float(sin(_x)),float(cos(_x)),0},
                                       {0,0,0,1}
                                     };
    float matrixRotY[4][4] = { {float(cos(_y)),0,float(sin(_y)),0},
                                        {0,1,0,0},
                                        {float(-sin(_y)),0,float(cos(_y)),0},
                                        {0,0,0,1}
                                      };
    float matrixRotZ[4][4] = { {float(cos(_z)),float(-sin(_z)),0,0},
                                        {float(sin(_z)),float(cos(_z)),0,0},
                                        {0,0,1,0},
                                        {0,0,0,1}
                                      };
    TransformMatrix _trasfomrMatrixRotX(matrixRotX);
    TransformMatrix _trasfomrMatrixRotY(matrixRotY);
    TransformMatrix _trasfomrMatrixRotZ(matrixRotZ);

    return  _trasfomrMatrixRotX * _trasfomrMatrixRotY * _trasfomrMatrixRotZ;
}

TransformMatrix TransformMatrixBuilder::createMoveMatrix(float x, float y, float z){
    /* Перемещение матрицы */
    float matrixMove[4][4] = { {1,0,0,0},
                                        {0,1,0,0},
                                        {0,0,1,0},
                                        {x,y,z,1}
                                      };
    TransformMatrix _transfomrMatrixMove(matrixMove);
    return _transfomrMatrixMove;
}

TransformMatrix TransformMatrixBuilder::createScaleMatrix(float x, float y, float z){
    /* Масштабирование */
    float matrixScale[4][4] = { {x,0,0,0},
                                         {0,y,0,0},
                                         {0,0,z,0},
                                         {0,0,0,1}
                                      };
    TransformMatrix _transfomrMatrixScale(matrixScale);
    return _transfomrMatrixScale;
}
