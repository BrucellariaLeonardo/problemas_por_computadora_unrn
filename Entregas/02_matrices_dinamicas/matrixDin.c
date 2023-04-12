#include "matrixDin.h"


matrixT matrixLoader(char* fPath)
// recibe un archivo y lee una matriz desde el mismo
{
    // abro mi archivo
    FILE* fptr = fopen(fPath, "r");
    // compruebo que el archivo se pudo abrir
    if (fptr == NULL)
    {
        printf("Fallo al abrir el archivo\n");
        exit(-1);
    }
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
    matriz.data = calloc(matriz.dimFil, sizeof(int*)); //creo el arreglo para guardar cada fila
    if(matriz.data == NULL)
    {
        printf("fallo crendo la mtriz");
        exit(-1);
    }
    for(int i = 0; i<matriz.dimFil; i++) //cargo en las filas las posiciones correspondientes a cada columna
    {
        matriz.data[i] = calloc(matriz.dimCol, sizeof(int));
        if(matriz.data[i] == NULL)
        {
            printf("fallo crendo la mtriz");
            exit(-1);
        }
    }
    // tomo elemento a elemento los datos del archivo para cargarlos en mi matriz
    for(int fil=0; fil< matriz.dimFil; fil++)
    {
        for(int col=0; col<matriz.dimCol; col++)
        {
                //fread(&buff, sizeof(int), 1, fptr);
                if(!feof(fptr))
                {
                    fscanf(fptr, "%d", &(matriz.data[fil][col]));
                    //printf("%d\t", buff);
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