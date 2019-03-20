#include "matrixc2.h"

void main(void)
{
    struct MatrixInt2 Matrix;
    int contlin, contcol;

    puts("Introduceti numarul de linii: ");
    scanf("%d",&Matrix.NrLin);

    puts("Introduceti numarul de coloane: ");
    scanf("%d",&Matrix.NrCol);
    
    
    if(!AllocMatrixInt2(&Matrix))
        return;

    PrintMatrixInt2(&Matrix); /*Matricea nu a fost initializata ...*/

    for(contlin = 0; contlin < Matrix.NrLin; contlin++)
        for(contcol = 0; contcol < Matrix.NrCol; contcol++)
                Matrix.Matrix[contlin][contcol] = contlin+ contcol;

    PrintMatrixInt2(&Matrix);

    FreeMatrixInt2(&Matrix);

    /*Apel aproape incorect. Era rau tare daca functia FreeMatrixInt2 nu stia sa rezolva situatia ...*/
    FreeMatrixInt2(&Matrix);

    /*free(Matrix.Matrix);*/ /*Apel total eroant.*/

    getch();
}
