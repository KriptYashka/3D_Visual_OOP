#include "transformmatrix.h"

TransformMatrix::TransformMatrix(float matr[MATRIX_ROW][MATRIX_COL]){
    for(int i = 0 ; i < MATRIX_ROW; ++i)
        for(int j =0 ; j < MATRIX_COL; ++j)
            _matr[i][j] = matr[i][j];
}

TransformMatrix::TransformMatrix(){
    for(int i = 0; i < MATRIX_ROW; ++i)
        for(int j = 0; j < MATRIX_COL; ++j)
            _matr[i][j] = 0;
}

TransformMatrix TransformMatrix::operator*(TransformMatrix _transformMatrix){
    TransformMatrix resMatr;

    for (int i = 0; i < MATRIX_ROW; i++)
        for (int j = 0; j < MATRIX_COL; j++)
            for (int k = 0; k < MATRIX_COL; k++)
                resMatr._matr[i][j] += _matr[i][k] * _transformMatrix._matr[k][j];

    return resMatr;
}

Point TransformMatrix::TransformPoint(Point point){
    Point newPoint;

    newPoint.x = point.x * _matr[0][0] + point.y * _matr[0][1] + point.z * _matr[0][2] + _matr[3][0];
    newPoint.y = point.x * _matr[1][0] + point.y * _matr[1][1] + point.z * _matr[1][2] + _matr[3][1];
    newPoint.z = point.x * _matr[2][0] + point.y * _matr[2][1] + point.z * _matr[2][2] + _matr[3][2];

    return newPoint;
}
