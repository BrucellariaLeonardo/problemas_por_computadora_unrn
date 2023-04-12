#include "matrices.h"

/////////////internas////////////////
matrixT initMat(int row, int col)
{
 matrixT mat;
 mat.dimCol = col;
 mat.dimFil = row;
 mat.lenData = 0;
 mat.memSize = row*col*extension;
 mat.matrix = calloc(mat.memSize, sizeof(matrixData));
 if(mat.matrix == NULL){
    mat.memSize = 0;
 }
 return mat;
}

int memFull(matrixT mat)
//retorna 1 si la memoria esta llena y 0 cc
{
    int full = 0;
    if(mat.memSize == mat.lenData)
    {
        full = 1;
    }
    return full;
}
void extendMem(matrixT *mat)
{
    int newMemSize = mat->memSize + mat->dimCol*mat->dimFil*extension;
    if(newMemSize > mat->dimCol*mat->dimFil) //corroboro de no alocar mas posiciones de las que puede tener la matriz
    {
        newMemSize = mat->dimCol*mat->dimFil;
    }
    realloc(mat->matrix, newMemSize*sizeof(matrixData));
    mat->memSize = newMemSize;
    return;
}

int findCord(matrixT mat, int row, int col)
//busca el indice de la coordenada recibida y en caso de no encontrarla devuelve el indice a la primer coordenada superior a la buscada 
//se asume que la matriz no esta vacia
{
    int i;
    for(i=0; i<mat.lenData; i++)
    {
        if((mat.matrix[i].cord.row > row) || (mat.matrix[i].cord.row == row && mat.matrix[i].cord.col > col))
        {
            break;
        }
    }
    return i;
}

void shiftMat(matrixT* mat, int index)
//se recibe un indice i, de modo que todos los elementos, incluido i son movidos una posicion a la derecha
//se asume que la memoria no esta llena
{
    for(int i = mat->lenData; i>index; i--)
    {
        mat->matrix[i] = mat->matrix[i-1];
    }
    return;
}
/////////////De usuario////////////////
void addElement(matrixT* mat, float data, int row, int col)
{
    int index;
    if(memFull(*mat))
    {
    //si se lleno alocar memoria para el elemento nuevo
        extendMem(mat);
    }
    //buscar la posicion en la que se inserta el elemento
    if(!itsEmpy(*mat))
    {
        index = findCord(*mat, row, col);
        if(mat->matrix[index].cord.col == col && mat->matrix[index].cord.row == row) //si el elemento ya existe, se actualiza el dato
        {
            mat->matrix[index].data = data;
        }else
        {
            //insertar el elemento
            if(!itsFull(*mat))
            {
                if(mat->matrix[index].cord.col < col && mat->matrix[index].cord.row < row) //si el elemento ya existe, se actualiza el dato
                {
                    mat->matrix[index].cord.col = col;
                    mat->matrix[index].cord.row = row;
                    mat->matrix[index].data = data;
                }else //se llego al final del arreglo
                {
                    shiftMat(mat, index);
                    mat->matrix[index].cord.col = col;
                    mat->matrix[index].cord.row = row;
                    mat->matrix[index].data = data;
                }
                mat->lenData ++;
            }
        }
    }else// si matriz esta vacia, se agrega el elemento en la primer posicion
    {
        mat->matrix[0].cord.col = col;
        mat->matrix[0].cord.row = row;
        mat->matrix[0].data = data;
        mat->lenData = 1;
    }
    return;
}
void loadRandMat(matrixT* mat, float fact)
{
    time_t t = time(NULL);
    srand(t);
    int dim = (mat->dimFil)*(mat->dimCol)*fact;
    for(int i = 0; i<dim; i++)
    {
        addElement(mat, rand()%8,rand()%mat->dimFil, rand()%mat->dimCol);
    }
}

int itsEmpy(matrixT mat)
//retorna 1 si la matriz esta vacia y 0 caso contrario
{
    int empy = 0; 
    if(mat.lenData == 0)
    {
        empy = 1;
    }
    return empy;
}
int itsFull(matrixT mat)
//retorna 1 si la matriz esta llena y 0 caso contrario
{
    return mat.lenData == mat.dimCol*mat.dimFil;
}

/*float* position(matrixT mat, int row, int col);
// En caso de que la posicion exista, retorna un puntero al elemento en la posicion anterior a la buscada
// Si la posicion buscada es el primer elemento, se retorna NULL
// en caso de que no exista y todos los elementos sean anteriores al elemento que busco, se retorna el ultimo elemento de la matriz
// en caso de que no exista y haya elementos mayores, se retorna un puntero al ultimo elemento anterior a la posicion buscada
// en caso de que el primer elemento de la matriz sea mayor a la posicion buscada, se retorna un puntero a null
*/

/*
matrixT resize(float datum, int row, int col, matrixData* next);
void setElement(matrixT* mat, float datum, int row, int col);
float getelement(matrixT mat, int row, int col);
///////////externas////////////////////
void cargarMatriz(int mat[DIM][DIM])
/* Se recibe una matriz estatica y se la inicializa con valores iguales a la suma de las componentes de la posicion del valor
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
*/
/* Se imprime la matriz
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
*/
/* suma de la matriz A y la matriz B, la cual es guardada en la matriz res
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
*/
/* Escalado de una mtriz por una constante
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
*/
/* Multiplicacion de dos matrices
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
*/