#include "transformmatrix.h"

TransformMatrix::TransformMatrix(double matr[MATRIX_ROW][MATRIX_COL]){
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
    /* Умножение двух матриц друг с другом. Перегрузка оператора умножения. */
    TransformMatrix resMatr;

    for (int i = 0; i < MATRIX_ROW; i++)
        for (int j = 0; j < MATRIX_COL; j++)
            for (int k = 0; k < MATRIX_COL; k++)
                resMatr._matr[i][j] += _matr[i][k] * _transformMatrix._matr[k][j];

    return resMatr;
}

Point TransformMatrix::TransformPoint(Point point){
    /* Смещение точки относительно значениям матрицы */
    Point newPoint;
    double offset = 0;

    newPoint.x = offset + (point.x * _matr[0][0] + point.y * _matr[0][1] + point.z * _matr[0][2] + _matr[3][0]);
    newPoint.y = offset + (point.x * _matr[1][0] + point.y * _matr[1][1] + point.z * _matr[1][2] + _matr[3][1]);
    newPoint.z = offset + (point.x * _matr[2][0] + point.y * _matr[2][1] + point.z * _matr[2][2] + _matr[3][2]);

    return newPoint;
}
