#include "matrixDin.h"

int main()
{
    matrixData *data, *data2, *data1, *res;
    matrixT mat;
    float x;
    mat.dimCol = 3;
    mat.dimFil = 3;
    mat.first = NULL;
    setElement(&mat, 3.5, 0,0);
    setElement(&mat, 2, 1,0);
    setElement(&mat, 5, 0,1);
    res = position(mat, 0,1);
    res = position(mat, 1,0);
    res = position(mat, 0,0);
    x = getelement(mat, 1,0);
    x = getelement(mat, 1,1);
    x = getelement(mat, 0,0);
    x = getelement(mat, 0,1);
    return 0;
}