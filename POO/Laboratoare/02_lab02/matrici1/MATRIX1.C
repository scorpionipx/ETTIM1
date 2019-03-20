#include "matrixc1.h"

void main(void)
{
    int **Matrix = NULL;
    int NrLin, NrCol;
    int contlin, contcol;

    puts("Introduceti numarul de linii: ");
    scanf("%d",&NrLin);

    puts("Introduceti numarul de coloane: ");
    scanf("%d",&NrCol);
    
    
    if(!AllocMatrixInt2(&Matrix, NrLin, NrCol))
        return;

    PrintMatrixInt2(Matrix, NrLin, NrCol); /*Matricea nu a fost initializata ...*/

    for(contlin = 0; contlin < NrLin; contlin++)
        for(contcol = 0; contcol < NrCol; contcol++)
                Matrix[contlin][contcol] = contlin+ contcol;

    PrintMatrixInt2(Matrix, NrLin, NrCol);

    FreeMatrixInt2(&Matrix, NrLin);

    /*Apel aproape incorect. Era rau tare daca functia FreeMatrixInt2 nu stia sa rezolva situatia ...*/
    FreeMatrixInt2(&Matrix, NrLin);

    /*free(Matrix);*/ /*Apel total eroant.*/

    getch();
}
