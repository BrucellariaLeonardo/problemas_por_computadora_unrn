#include "matrices.h"

void cargarMatriz(int mat[DIM][DIM])
/* Se recibe una matriz estatica y se la inicializa con valores iguales a la suma de las componentes de la posicion del valor*/
{
    for (int fila=0; fila < DIM; fila++)
    {
        for(int columna=0; columna<DIM; columna++)
        {
            mat[fila][columna] = fila+columna;
        }
    }
return;
}

void mostrarMatriz(int mat[DIM][DIM])
/* Se imprime la matriz*/
{
    for (int fila=0; fila <DIM; fila++)
    {
        for(int columna=0; columna<DIM; columna++)
        {
            printf("%d\t", mat[fila][columna]);
        }
        printf("\n");
    }
return;
}

void suma(int A[DIM][DIM], int B[DIM][DIM], int res[DIM][DIM])
/* suma de la matriz A y la matriz B, la cual es guardada en la matriz res*/
{
    int fila, columna = 0;
    for(fila = 0; fila<DIM; fila++)
    {
        for(columna = 0; columna<DIM; columna++) //posicion a calcular [fila,columna]
        {
            res[fila][columna] = A[fila][columna] + B[fila][columna];
        }
    }
    return;
}

void escalar(int A[DIM][DIM], int factor)
/* Escalado de una mtriz por una constante*/
{
    for ( int fila = 0; fila<DIM; fila++)
    {
        for( int columna = 0; columna<DIM; columna++)
        {
            A[fila][columna] = A[fila][columna] * factor;
        }
    }
    return;
}

void transponer(int A[DIM][DIM] )
{
    for(int fila = 0; fila<DIM; fila++)
    {
        for( int columna = 0; columna<fila; columna++)
        {
            int aux;    
            aux = A[fila][columna];
            A[fila][columna] = A[columna][fila];
            A[columna][fila] = aux;
        }
    }
    return;
}

void mult(int A[DIM][DIM], int B[DIM][DIM], int res[DIM][DIM])
/* Multiplicacion de dos matrices*/
{
    for(int fila = 0; fila<DIM; fila++)
    {
        for(int columna = 0; columna< DIM; columna++) //posicion a calcular [fila, columna]
        {
            res[fila][columna] = 0; // inicializacion del valor donde se guardara el resultado
            for(int index = 0; index < DIM; index++) // ciclo para recorrer las multiplicaciones a sumar
            {
                res[fila][columna] += A[fila][index] * B[index][columna]; // se acumula el resultado de cada producto en la posicion destino
            }
        }
    }
    return;
}
