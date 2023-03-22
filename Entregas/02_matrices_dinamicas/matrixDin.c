#include "matrixDin.h"
int** matrixAloc(int dim1,int dim2)
// funcion interna de la libreria, que se encarga de reservar memoria para almacenar los datos de una matriz
{
    int** mat;
    mat = calloc(dim1, sizeof(int*)); //creo el arreglo para guardar cada fila
    if( mat == NULL)
    {
        printf("Fallo al reservar memoria.");
        exit(-1);
    }
    for (int i=0; i<dim1; i++)
    {
        mat[i] = calloc(dim2, sizeof(int)); //creo los arreglos de cada columna asociada a cada fila
        if(mat[i] == NULL)
        {
            printf("Fallo al reservar memoria.");
            exit(-1);
        }
    }
    return mat;
}

matrixT matrixLoader(FILE *fptr)
// recibe un archivo y lee una matriz desde el mismo
{
    // creo la estructura donde voy a guardar lo leido del archivo
    matrixT matriz;
    // tomo el primer elemento del archivo para guardarlo en la dimension de la fila de la estructura
    if(!feof(fptr))
    {
        fscanf(fptr, "%d", &(matriz.dimFil));
    }else
    {
        printf("fallo obteninedo la fila");
        exit(-1);
    }
    // tomo el segundo elemento del archivo para guardarlo en la dimension de la columna de la estructura
    if(!feof(fptr))
    {
        fscanf(fptr, "%d", &(matriz.dimCol));
    }    
    // aloco la ma memoria para mi matrix y guardo la direccion de ese puntero
    matriz.data = matrixAloc(matriz.dimFil, matriz.dimCol);
    // tomo elemento a elemento los datos del archivo para cargarlos en mi matriz
    for(int fil=0; fil< matriz.dimFil; fil++)
    {
        for(int col=0; col<matriz.dimCol; col++)
        {
                if(!feof(fptr))
                {
                    fscanf(fptr, "%d", &(matriz.data[fil][col]));
                }else
                {
                    printf("Fallo obteniendo los valores de la mtriz, compruebe que su archivo este bien definido.");
                }
        }
    }
    return matriz;
}

void printMatrix(matrixT matrix)
//recibe una matriz y la muestr por pantalla
{
    for(int fil=0; fil<matrix.dimFil; fil++)
    {
        printf("[");
        for(int col=0; col<matrix.dimCol; col++)
        {
            printf("%d", (matrix.data[fil][col]));
            if(col < matrix.dimCol-1)
            {
                printf("\t");
            }
        }
        printf("]\n");
    }
}
matrixT addMat(matrixT A, matrixT B)
// se reciben dos matrices de las mismas dimensiones y retrona su suma
{
    matrixT res;
    res.dimCol = A.dimCol;
    res.dimFil = A.dimFil;
    res.data = matrixAloc(res.dimFil, res.dimCol);
    for (int fil = 0; fil<A.dimFil; fil++)
    {
        for(int col=0; col<A.dimCol; col++)
        {
            res.data[fil][col]= A.data[fil][col] + B.data[fil][col];
        }
    }
    return res;
}
void freeMat(matrixT mat)
// libera la memoria de una matriz
{
    for( int fil=0; fil<mat.dimFil; fil++)
    {
        free(mat.data[fil]);
    }
    free(mat.data);
    return;
}
