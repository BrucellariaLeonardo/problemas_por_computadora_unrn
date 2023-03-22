#ifndef matrixDin
#define matrixDin

#include <stdio.h>
#include <stdlib.h>

typedef struct matrixT
{
    int dimFil, dimCol;
    int** data;
} matrixT;


matrixT matrixLoader(FILE* fptr);
void printMatrix(matrixT matrix);
matrixT addMat(matrixT A, matrixT B);
void freeMat(matrixT mat);

#endif