# include "main.h"


int main(int argc, char* argv[])
{
    matrixT mat1,mat2;
    mat1 = matrixLoader(argv[1]);
    mat2 = matrixLoader(argv[2]);
    printMatrix(addMat(mat1,mat2));
    return 0;
}