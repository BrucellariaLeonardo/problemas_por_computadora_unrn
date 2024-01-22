# include "main.h"


int main(int argc, char* argv[])
//se reciben 2 archivos con matrices y un archivo de salida opcional (ejemplo de llamado ./ejecutable mat1.txt mat2.txt salida.txt)
{
    matrixT mat[3];
    FILE *fptr;
    if(argc == 3 || argc == 4)
    {
        //carga del archivo
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
        //sumo dos matrices y muestro el resultado
        mat[2] = addMat(mat[0],mat[1]);
        printMatrix(mat[0]);
        printf("+\n");
        printMatrix(mat[1]);
        printf("--------------------------\n");
        printMatrix(mat[2]);
        //escalo matriz resultado por 3
        printf("\n\nmatriz escalada por 3");
        escalarMat(mat[2], 3);
        printf("\n");
        printMatrix(mat[2]);
        //si recibi un archivo de salida lo escribo en ese archivo
        if(argc == 4) 
        {
            printf("\nmatriz obtenida en el archivo de salida:\n");
            matrixExport("salida.txt", mat[2]);
            fptr = fopen("salida.txt", "r");
            printMatrix( matrixLoader( fptr ) );
            fclose(fptr);
        }
        //Diagonalizo la matriz
        printf("\nmatriz sin diagonalizar:\n");
        printMatrix(mat[0]);
        printf("\nmatriz diagonalizada:\n");
        mat[0] = diag(mat[0]);
        printMatrix(mat[0]);
        //Muestro una submatriz de la primer matriz recibida
        printf("\nsub matriz:\n");
        printMatrix(subMat(mat[0],1,0));
        //libero la memoria de las matrices
        for(int i; i<3; i++)
        {
            freeMat(mat[i]);
        }
        return 0;
    }else{
        fprintf(stderr,"Numero de parametros invalido.\n");
        exit(-2);
    }
    //comprobar que es diagonalizable
    
    //volver 0 la primer componente
        //escalar la primer fila y resarla de cada fila inferior
    //volver 0 la segunda
    //....
    //volver 0 la n esima
    
       
}