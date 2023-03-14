#ifndef matrices
#define matrices

#include <stdio.h>
#include <math.h>
#include "constantes.h"

#endif

void cargarMatriz(int mat[DIM][DIM]);
void mostrarMatriz(int mat[DIM][DIM]);
void suma(int A[DIM][DIM], int B[DIM][DIM], int res[DIM][DIM]);
void escalar(int MAT[DIM][DIM], int factor);
void transponer(int A[DIM][DIM] );
void mult(int A[DIM][DIM], int B[DIM][DIM], int res[DIM][DIM]);
