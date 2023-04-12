#include "matrixDin.h"
///////////operaciones internas////////

matrixData* position(matrixT mat, int row, int col)
// En caso de que la posicion exista, retorna un puntero al elemento en la posicion anterior a la buscada
// Si la posicion buscada es el primer elemento, se retorna NULL
// en caso de que no exista y todos los elementos sean anteriores al elemento que busco, se retorna el ultimo elemento de la matriz
// en caso de que no exista y haya elementos mayores, se retorna un puntero al ultimo elemento anterior a la posicion buscada
// en caso de que el primer elemento de la matriz sea mayor a la posicion buscada, se retorna un puntero a null
{
    matrixData* current;
    if(mat.first->f > row || (mat.first->f == row && mat.first->c >= col)){
        current = NULL;
    }else{
        current = mat.first;
        while ((current->next != NULL) && (current->next->f <row)) //me posiciono en la fila
        {
            current = current->next;
        }
        while ((current->next != NULL) && (current->next->f == row) && (current->next->c < col)) //me posiciono en la columna
        {
            current = current->next;
        }
    }
    return current;
}


matrixData* alocateNode(float datum, int row, int col, matrixData* next)
{
    matrixData* new = (matrixData*) malloc(sizeof(matrixData));
    new->c = col;
    new->f = row;
    new->data = datum;
    new->next = next;
    return new;
}
void setElement(matrixT* mat, float datum, int row, int col)
{
    if(mat->first == NULL) // si la matriz esta vacia
    {
        mat->first = alocateNode(datum, row, col, NULL);
    }else{
        matrixData* element = position(*mat, row, col); // me posiciono en el elemento anteior a la posicion donde se inserta el nuevo
        if (element == NULL) //el elemento nuevo es la primea posicion de la matriz
        {
            mat->first = alocateNode(datum,row,col,mat->first);
        }
        else if(element->next == NULL) //si el elemento nuevo es el ultimo
        {
            element->next = alocateNode(datum, row, col, NULL);
        }else if((element->next->c == col) && (element->next->f == row)) //si el elemento existe, lo sobreescribo
        {
            element->next->data = datum;
        }else{ //sino, el proximo elemento es superior al que estoy buscando, asique inserto mi elemento entre el actual y el proximo
            element->next = alocateNode(datum,row, col, element->next);
        }
    }
    return;
}
float getelement(matrixT mat, int row, int col)
//retorna 0 para cualquier posicion no definida y sino el valor almacenado en la posicion
{
    float data = 0;
    if(mat.first != NULL)
    {
        matrixData* element = position(mat, row, col);
        if( element == NULL) //si me estaban pidiendo el primer elemento
        {
            if((mat.first->c == col) && (mat.first->f == row))
            {
                data = mat.first->data;
            }            
        }
        else if((element->next != NULL) && (element->next->c == col) && (element->next->f == row))
        {
            data = element->next->data;
        }

    }
    return data;
}


/////////operaciones de usuario////////
/*
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
*/
/*matrixT matrixLoader(FILE *fptr)
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
/*
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
float det(matrixT mat, int start, int end)
{
    float acum = 0;
    if ((mat.dimFil != 1) || (mat.dimCol != 1))
    {
        for(int c=start; c<mat.dimCol; c++)
        {
            if(!(c)%2)
            {
                acum += mat.data[0][c] * det(mat,start+1, end)
//                acum += mat.data[0][c] * det(subMat(mat,0,c));
            }else{
//                acum -= mat.data[0][c] * det(subMat(mat,0,c));
            }
        }
    }else{
        acum = mat.data[0][0];
    }
    return acum;
}*/