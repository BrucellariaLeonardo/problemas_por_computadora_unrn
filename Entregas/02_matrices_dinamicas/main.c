# include "main.h"


int main(int argc, char* argv[])
//se reciben 2 archivos con matrices y un archivo de salida opcional
{
    matrixT mat[3];
    FILE *fptr;
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
                   fprintf(stderr, "Fallo al abrir el archivo %s. Error: %s\n", argv[arg], strerror(errno));
                    exit(-1);
                }
        }
        mat[2] = addMat(mat[0],mat[1]);
        printMatrix(mat[0]);
        printf("+\n");
        printMatrix(mat[1]);
        printf("--------------------------\n");
        printMatrix(mat[2]);
        escalarMat(mat[2], 3);
        printf("\n");
        printMatrix(mat[2]);
        if(argc == 4) //si recibi un archivo de salida lo escribo
        {
            matrixExport("salida.txt", mat[2]);
            FILE *fp = fopen("salida.txt", "r");
            printf("\nmatriz obtenida en el archivo de salida:\n");
            printMatrix( matrixLoader( fp ) );
        }
        for(int i; i<3; i++)
        {
            freeMat(mat[i]);
        }
    }else{
        fprintf(stderr,"Numero de parametros invalido.\n");
        exit(-2);
    }
    return 0;   
}