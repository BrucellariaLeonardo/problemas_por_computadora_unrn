# include "main.h"


int main(int argc, char* argv[])
{
    matrixT auxi;
    auxi = matrixLoader(argv[1]);
    printMatrix(auxi);
    return 0;
}