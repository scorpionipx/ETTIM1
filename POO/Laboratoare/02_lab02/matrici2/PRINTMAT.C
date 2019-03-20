#include "matrixc2.h"

/*Tipareste la consola matricea de intregi specificata.*/
void PrintMatrixInt2(struct MatrixInt2 *PtrMatrix)
{
    char Test;
    int contlin, contcol;

    puts("Sa afisez matricea ? (y/n)");
    do
    {
        Test = toupper(getch());
    }
    while(Test != 'Y' && Test != 'N');

    if(Test == 'Y')
    {
        puts("Matricea este :");
        for(contlin = 0; contlin < PtrMatrix->NrLin; contlin++)
        {
            for(contcol = 0; contcol < PtrMatrix->NrCol; contcol++)
                    printf("%3d",PtrMatrix->Matrix[contlin][contcol]);
            printf("\n");
        }
    }
}
