#ifndef matrices
#define matrices

#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
typedef struct coordinateT
{
    int row, col;
}coordinateT;
typedef struct matrixData
{
    coordinateT cord;         //aqui se almacenan los indices de la posicion del dato
    float data;     
}matrixData; //estructura preparada para los datos de una posicion de la mtriz
typedef struct matrixT
{
    int dimFil, dimCol; //dimensiones de la matriz
    matrixData *matrix; // datos de la matriz, y sus respectivos indices
    int lenData, memSize;        //indicador de cuantos elementos definidos posee la matriz
}matrixT;
matrixT initMat(int row, int col);



#endif
/*
void cargarMatriz(int mat[DIM][DIM]);
void mostrarMatriz(int mat[DIM][DIM]);
void suma(int A[DIM][DIM], int B[DIM][DIM], int res[DIM][DIM]);
void escalar(int MAT[DIM][DIM], int factor);
void transponer(int A[DIM][DIM] );
void mult(int A[DIM][DIM], int B[DIM][DIM], int res[DIM][DIM]);

*/