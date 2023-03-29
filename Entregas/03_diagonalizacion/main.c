# include "main.h"


int main(int argc, char* argv[])
//se reciben 2 archivos con matrices y un archivo de salida opcional
{
    matrixT mat[3];
    FILE *fptr;
//carga del archivo
    if(argc == 3 || argc == 4)
    {
        for (int arg=1;arg<3; arg++) //recorro los parametros recibidos de la terminal
        {
            fptr = fopen(argv[arg],"r");
                if(fptr != NULL)
                {
                    mat[arg-1] = matrixLoader(fptr);
                    fclose(fptr);
                }else
                {
                    printf("fallo al abrir el archivo");
                    exit(-1);
                }
        }
    }else{
        printf("Numero de parametros invalido.");
        exit(-2);
    }
    //comprobar que es diagonalizable
    
    //volver 0 la primer componente
        //escalar la primer fila y resarla de cada fila inferior
    //volver 0 la segunda
    //....
    //volver 0 la n esima
    printMatrix(mat[0]);
    addFil(&mat[0], 0,1);
    printf("\n");
    printMatrix(mat[0]);

    //printMatrix(subMat(mat[0],1,0));
    /*printf("%.2f", det(mat[0]));
        for(int i; i<3; i++)
        {
            freeMat(mat[i]);
        }*/
    return 0;
       
}