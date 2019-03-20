#include "matrixc2.h"

/*Aloca dinamic memorie pentu o matrice cu NrLin linii si NrCol coloane.
Returneaza error sau success.*/
int AllocMatrixInt2(struct MatrixInt2 *PtrMatrix)
{
    int contorlin;
    int **MatrixTemp;

    /*Se aloca memorie pentru pointeri la linii ...*/
    PtrMatrix->Matrix = (int **)malloc(PtrMatrix->NrLin * sizeof(int *));
    if(AllocError(PtrMatrix->Matrix))
        return error;

    MatrixTemp = PtrMatrix->Matrix;
    for(contorlin = 0; contorlin < PtrMatrix->NrLin; (contorlin++, MatrixTemp++))
    {
        /*Se aloca memorie pentru o linie ...*/
        *MatrixTemp = (int *)malloc(PtrMatrix->NrCol * sizeof(int));
        if(AllocError(*MatrixTemp))
        {
            /*In caz de eroare la alocare se sterge memoria deja alocata ...*/
            PtrMatrix->NrLin = contorlin;
            FreeMatrixInt2(PtrMatrix);
            free(PtrMatrix->Matrix);
            PtrMatrix->Matrix = NULL;
            PtrMatrix->NrLin = 0;
            PtrMatrix->NrCol = 0;
            return error;
        }
    }
    return success;
}

/*Elibereaza memoria alocata dinamic pentru o matrice. Memoria poate fi alocata folosind
malloc sau calloc !!! Returneaza error sau success.*/
int FreeMatrixInt2(struct MatrixInt2 *PtrMatrix)
{
    int contlin;
    int **MatrixTemp = PtrMatrix->Matrix;

    /*Se testeaza daca memoria pentru matrice a fost alocata ...*/
    if(NULLMemTest(PtrMatrix->Matrix))
        return error;
    /*Se sterge memoria pe linii ...*/
    for(contlin = 0; contlin < PtrMatrix->NrLin; (contlin++, MatrixTemp++))
    {
        /*Se testeaza daca a fost alocata memorie pentru linia curenta ...*/
        if(NULLMemTest(*MatrixTemp))
                return error;
        free(*MatrixTemp); /*Se sterge memoria pentru linia curenta ...*/
    }
    free(PtrMatrix->Matrix);
    PtrMatrix->Matrix = NULL;
    PtrMatrix->NrLin = 0;
    PtrMatrix->NrCol = 0;
    return success;
}


