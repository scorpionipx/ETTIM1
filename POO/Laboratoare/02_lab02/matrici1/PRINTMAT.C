#include "matrixc1.h"

/*Tipareste la consola matricea de intregi specificata.*/
void PrintMatrixInt2(int **Matrix, int NrLin, int NrCol)
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
        for(contlin = 0; contlin < NrLin; contlin++)
        {
            for(contcol = 0; contcol < NrCol; contcol++)
                    printf("%3d",Matrix[contlin][contcol]);
            printf("\n");
        }
    }
}
