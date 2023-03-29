#include "matrixDin.h"
/// funciones internas////
float** matrixAloc(int dim1,int dim2)
// funcion interna de la libreria, que se encarga de reservar memoria para almacenar los datos de una matriz
{
    float** mat;
    mat = calloc(dim1, sizeof(float*)); //creo el arreglo para guardar cada fila
    if( mat == NULL)
    {
        printf("Fallo al reservar memoria.");
        exit(-1);
    }
    for (int i=0; i<dim1; i++)
    {
        mat[i] = calloc(dim2, sizeof(float)); //creo los arreglos de cada columna asociada a cada fila
        if(mat[i] == NULL)
        {
            printf("Fallo al reservar memoria.");
            exit(-1);
        }
    }
    return mat;
}
void addFil(matrixT* mat, int filRes, int filSour)
//operacion inplace para sumar filas de una matriz
{
    for( int c=0; c<mat->dimCol; c++)
    {
        mat->data[filRes][c] = mat->data[filRes][c] + mat->data[filSour][c];
    }
    return;
}
void subFil(matrixT* mat, int filRes, int filSour)
//operacion inplace para restar filas
{
    for( int c=0; c<mat->dimCol; c++)
    {
        mat->data[filRes][c] = mat->data[filRes][c] - mat->data[filSour][c];
    }
    return;
}
void scaleFil(matrixT* mat, int fil, int fact)
//operacion inplace para escalar una fila por un factor fact
{
    for( int c=0; c<mat->dimCol; c++)
    {
        mat->data[fil][c] = fact * (mat->data[fil][c]);
    }
    return;
}
void filPermutation(matrixT* mat, int filA, int filB)
{
    float aux;
    for(int c=0; c<mat->dimCol; c++)
    {
        aux = mat->data[filA][c];
        mat->data[filA][c] = mat->data[filB][c];
        mat->data[filB][c] = aux;
    }
    return;
}
void colPermutation(matrixT* mat, int colA, int colB)
{
    float aux;
    for(int c=0; c<mat->dimFil; c++)
    {
        aux = mat->data[c][colA];
        mat->data[c][colA] = mat->data[c][colB];
        mat->data[c][colB] = aux;
    }
    return;
}
///funcionalidades de usuario///
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
                    fscanf(fptr, "%f", &(matriz.data[fil][col]));
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
            printf("%.2f", (matrix.data[fil][col]));
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
void escalarMat(matrixT mat, float escalar)
{
    for(int fil=0; fil<mat.dimFil; fil++)
    {
        for(int col=0; col<mat.dimCol; col++)
        {
            mat.data[fil][col] = mat.data[fil][col]*escalar;    
        }
    }
    return;
}
matrixT subMat(matrixT mat, int fil, int col)
{
    matrixT sub;
    sub.dimCol = mat.dimCol-1;
    sub.dimFil = mat.dimFil-1;
    sub.data = matrixAloc(sub.dimFil, sub.dimCol);
    for(int f=0; f<fil; f++)
    {
        for(int c=0; c<col; c++)
        {
            sub.data[f][c] = mat.data[f][c];
        }
        for(int c=col+1; c<mat.dimCol; c++)
        {
            sub.data[f][c-1] = mat.data[f][c];
        }
    }
    for(int f=fil+1; f<mat.dimFil; f++)
    {
        for(int c=0; c<col; c++)
        {
            sub.data[f-1][c] = mat.data[f][c];
        }
        for(int c=col+1; c<mat.dimCol; c++)
        {
            sub.data[f-1][c-1] = mat.data[f][c];
        }
    }
    return sub;
}
