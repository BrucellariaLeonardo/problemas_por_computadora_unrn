# include "main.h"


int main(int argc, char* argv[])
{
    matrixT auxi;
    auxi = matrixLoader(argc, argv[1]);
    for(int fil=0; fil<auxi.dimFil; fil++)
    {
        printf("[");
        for(int col=0; col<auxi.dimCol; col++)
        {
            printf("%d\t", (auxi.data[fil][col]));
        }
        printf("]\n");
    }
    return 0;
}