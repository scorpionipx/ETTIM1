#include "matrixc1.h"

/*Aloca dinamic memorie pentu o matrice cu NrLin linii si NrCol coloane.
Returneaza error sau success.*/
int AllocMatrixInt2(int ***Matrix, int NrLin, int NrCol)
{
    int contorlin, contorlinsupl;
    int **MatrixTemp;

    /*Se aloca memorie pentru pointeri la linii ...*/
    *Matrix = (int **)malloc(NrLin * sizeof(int *));
    if(AllocError(*Matrix))
        return error;
        
    MatrixTemp = *Matrix;
    for(contorlin = 0; contorlin < NrLin; (contorlin++, MatrixTemp++))
    {
        /*Se aloca memorie pentru o linie ...*/
        *MatrixTemp = (int *)malloc(NrCol * sizeof(int));
        if(AllocError(*MatrixTemp))
        {
            /*In caz de eroare la alocare se sterge memoria deja alocata ...*/
            MatrixTemp = *Matrix;
            for(contorlinsupl = 0; contorlinsupl < contorlin; (contorlinsupl++, MatrixTemp++))
                free(*MatrixTemp);
            free(*Matrix);
            *Matrix = NULL;
            return error;
        }
    }
    return success;
}

/*Elibereaza memoria alocata dinamic pentru o matrice. Memoria poate fi alocata folosind
malloc sau calloc !!! Returneaza error sau success.*/
int FreeMatrixInt2(int ***Matrix, int NrLin)
{
    int contlin;
    int **MatrixTemp = *Matrix;

    /*Se testeaza daca memoria pentru matrice a fost alocata ...*/
    if(NULLMemTest(*Matrix))
        return error;
    /*Se sterge memoria pe linii ...*/
    for(contlin = 0; contlin < NrLin; (contlin++, MatrixTemp++))
    {
        /*Se testeaza daca a fost alocata memorie pentru linia curenta ...*/
        if(NULLMemTest(*MatrixTemp))
                return error;
        free(*MatrixTemp); /*Se sterge memoria pentru linia curenta ...*/
    }
    free(*Matrix);
    *Matrix = NULL;
    return success;
}


