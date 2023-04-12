#ifndef matrixDin
#define matrixDin

#include <stdio.h>
#include <stdlib.h>
//typedef struct matrixData matrixData; //estructura diseñada para guardar una posicion de una matriz
//typedef struct matrixT matrixT; //estructura que guarda los datos de una matriz
typedef struct matrixData
{
    int f,c;        //coordenadas del dato
    float data;     
    struct matrixData* next;
}matrixData; //estructura preparada para guardar el inicio y el final de un intervalo

typedef struct matrixT
{
    int dimFil, dimCol; //dimensiones de la matriz
    matrixData* first;  //puntero al primer dato de la matriz
    //int lenData;        //indicador de cuantos elementos definidos posee la matriz
    // int num_inter    contador de cuantos intervalos con datos hay en la matriz
}matrixT;

matrixData* alocateNode(float datum, int row, int col, matrixData* next);
matrixData* position(matrixT mat, int row, int col);
void setElement(matrixT* mat, float datum, int row, int col);
float getelement(matrixT mat, int row, int col);


/*
matrixT matrixLoader(FILE* fptr);
void printMatrix(matrixT matrix);
matrixT addMat(matrixT A, matrixT B);
void freeMat(matrixT mat);
void escalarMat(matrixT mat, float escalar);
matrixT subMat(matrixT mat, int fil, int col);
float det(matrixT mat);
*/
#endif
