#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H
#include "point.h"
#include <iostream>

#define MATRIX_COL 4
#define MATRIX_ROW 4

class TransformMatrix{
private:
    double _matr[MATRIX_COL][MATRIX_ROW];
public:
    TransformMatrix();
    TransformMatrix(double matr[MATRIX_COL][MATRIX_ROW]);
    TransformMatrix operator*(TransformMatrix _transformMatrix);
    Point TransformPoint(Point point);
};

#endif // TRANSFORMMATRIX_H
