 /* Este  archivo se utiliza para realizar testeos de la biblioteca*/
#include "main.h"
int main(int argc, const char * argv[]) {
    int x[DIM][DIM], y[DIM][DIM], z[DIM][DIM];
    cargarMatriz (x);
    cargarMatriz (y);
    mult(x,y,z);
    mostrarMatriz(y);
    printf("\n");
    mostrarMatriz (z);

    return 0;
}