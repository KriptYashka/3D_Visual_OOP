#include "transformmatrixbuilder.h"

TransformMatrixBuilder::TransformMatrixBuilder(){}

TransformMatrix TransformMatrixBuilder::createRotationMatrix(float x, float y, float z){
    float _x = x*M_PI/180.0;
    float _y = y*M_PI/180.0;
    float _z = z*M_PI/180.0;

    float transfomrMatrixRotX[4][4] = { {1,0,0,0},
                                       {0,float(cos(_x)),float(-sin(_x)),0},
                                       {0,float(sin(_x)),float(cos(_x)),0},
                                       {0,0,0,1}
                                     };
    float transformMatrixRotY[4][4] = { {float(cos(_y)),0,float(sin(_y)),0},
                                        {0,1,0,0},
                                        {float(-sin(_y)),0,float(cos(_y)),0},
                                        {0,0,0,1}
                                      };
    float transformMatrixRotZ[4][4] = { {float(cos(_z)),float(-sin(_z)),0,0},
                                        {float(sin(_z)),float(cos(_z)),0,0},
                                        {0,0,1,0},
                                        {0,0,0,1}
                                      };
    TransformMatrix _trasfomrMatrixRotX(transfomrMatrixRotX);
    TransformMatrix _trasfomrMatrixRotY(transformMatrixRotY);
    TransformMatrix _trasfomrMatrixRotZ(transformMatrixRotZ);

    return  _trasfomrMatrixRotX * _trasfomrMatrixRotY * _trasfomrMatrixRotZ;
}

TransformMatrix TransformMatrixBuilder::createMoveMatrix(float x, float y, float z)
{
    float transfomrMatrixMove[4][4] = { {1,0,0,0},
                                        {0,1,0,0},
                                        {0,0,1,0},
                                        {x,y,z,1}
                                      };
    TransformMatrix _transfomrMatrixMove(transfomrMatrixMove);
    return _transfomrMatrixMove;
}

TransformMatrix TransformMatrixBuilder::createScaleMatrix(float x, float y, float z)
{
    float transfomrMatrixScale[4][4] = { {x,0,0,0},
                                         {0,y,0,0},
                                         {0,0,z,0},
                                         {0,0,0,1}
                                      };
    TransformMatrix _transfomrMatrixScale(transfomrMatrixScale);
    return _transfomrMatrixScale;
}
