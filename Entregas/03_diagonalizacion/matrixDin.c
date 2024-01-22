#include "matrixDin.h"
/// funciones internas////
float** matrixAloc(int dim1,int dim2)
// funcion interna de la libreria, que se encarga de reservar memoria para almacenar los datos de una matriz
{
    float** mat;
    mat = calloc(dim1, sizeof(float*)); //creo el arreglo para guardar cada fila
    if( mat == NULL)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(-1);
    }
    for (int i=0; i<dim1; i++)
    {
        mat[i] = calloc(dim2, sizeof(float)); //creo los arreglos de cada columna asociada a cada fila
        if(mat[i] == NULL)
        {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(-1);
        }
    }
    return mat;
}
void addScalFil(matrixT* mat, int filRes, int filSour, float scale)
//operacion inplace para sumar a filRes scale veces la fila filsour
{
    for( int c=0; c<mat->dimCol; c++)
    {
        mat->data[filRes][c] = mat->data[filRes][c] + scale * mat->data[filSour][c];
    }
    return;
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
void scaleFil(matrixT* mat, int fil, float fact)
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
        fprintf(stderr, "Fallo al cargar una matriz. Archivo de entrada corrupto.\n");
        exit(-1);
    }
    // tomo el segundo elemento del archivo para guardarlo en la dimension de la columna de la estructura
    if(!feof(fptr))
    {
        fscanf(fptr, "%d", &(matriz.dimCol));
    }else
    {
        fprintf(stderr, "Fallo al cargar una matriz. Archivo de entrada corrupto.\n");
        exit(-1);
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
                    fprintf(stderr, "Fallo al cargar una matriz. Archivo de entrada corrupto.\n");
                    exit(-1);
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

matrixT diag(matrixT mat)
{

    for(int f=0; f<mat.dimFil; f++) //ciclo para cada reduccion
    {
        if(mat.data[f][f] == 0) //si la fila es 0 en la diagonal principal la swapeo
        {
            int i=mat.dimFil-1;
            for(i; i>f; i--) //busco una fila con componente distinta de 0 (de abajo hacia arriba)
            {
                if(mat.data[i][f] != 0)
                {
                    break;
                }
            }
            if(i != f) //si encontre ninguna fila que cumpla
            {
                filPermutation(&mat, f, i);
            }/*else{ //si no encontre ninguna fila 
                printf("\n\n TO DO...\n\n"); //TO DO
            }*/
        } 
        if(mat.data[f][f] != 0){ // condicion verdadera si se encontro alguna fila distinta de 0
            scaleFil(&mat, f, 1/mat.data[f][f]); // la escalo
            for(int i=f+1; i<mat.dimFil; i++)  
            {
                addScalFil(&mat, i, f, -mat.data[i][f]);
            }
        }

    }
    return mat;
}
float det(matrixT mat)
{
    float acum1 = 0; //acumulador para los terminos positivos del determinante
    float acum2 = 0; // acumulador para los terminos negativos del determinante
    float det = 0;
   if ((mat.dimFil != 1) || (mat.dimCol != 1))
    {
        for (int f= 0; f<mat.dimFil; f++)
        {
            acum1 = 1;
            acum2 = 1;
            for (int c=0; c<mat.dimFil; c++)
            {
                if(f+c < mat.dimFil) //terminos podtivos del determinante
                {
                    acum1 = acum1*mat.data[c+f][c];
                    acum2 = acum2*mat.data[c+f][mat.dimCol-1-c];
                }else{
                    acum1 = acum1*mat.data[f+c-mat.dimFil][c];
                    acum2 = acum2*mat.data[f+c-mat.dimFil][mat.dimCol-1-c];

                }
            }
//            det += acum1 - acum2;
            det = det + acum1;
            det = det - acum2;
        }
    }else{
        det = mat.data[0][0];
    }
    return det;
}

void matrixExport(char fname[], matrixT matrix)
{
    // abro/creo el archivo de destino
    FILE *fptr = NULL;
    fptr = fopen( fname , "w");
    if(fptr == NULL)
    {
        fprintf(stderr, "Fallo al abrir el archivo de salida.Error: %s\n", strerror(errno));
        exit(-1);
    }else
    {
        // escribo la cantidad de filas y columnas de la matriz
        fprintf(fptr, "%d %d\n", matrix.dimFil, matrix.dimCol);
        
        // escribo los datos de la matriz
        for(int fil=0; fil<matrix.dimFil; fil++)
        {
            for(int col=0; col<matrix.dimCol; col++)
            {
                fprintf(fptr, "%f ", matrix.data[fil][col]);
            }
            fprintf(fptr, "\n");
        }
        //libero el archivo
        fclose(fptr);
    }
    return;
}