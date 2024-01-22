#ifndef matrixDin
#define matrixDin

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct matrixT
{
    int dimFil, dimCol;
    float** data;
} matrixT;


matrixT matrixLoader(FILE* fptr);
void printMatrix(matrixT matrix);
matrixT addMat(matrixT A, matrixT B);
void freeMat(matrixT mat);
void escalarMat(matrixT mat, float escalar);

void matrixExport(char fname[], matrixT matrix);

#endif