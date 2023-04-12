 /* Este  archivo se utiliza para realizar testeos de la biblioteca*/
#include "main.h"
int main(int argc, const char * argv[]) {
    matrixT mat;
    mat = initMat(10,10);
//    addElement(&mat, 1, 1, 0);
//    addElement(&mat,2, 3,3);
    loadRandMat(&mat, 0.1);
    return 0;
}