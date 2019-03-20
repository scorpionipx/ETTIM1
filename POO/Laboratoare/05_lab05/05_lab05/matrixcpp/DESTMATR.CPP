/************************************************
destmatr.cpp
************************************************/

#include "matrixcpp.hpp"

//Elibereaza memoria alocata dinamic pentru o matrice.
void MatrixInt2::ClearAndDestroy(void)
{
    if(!State)
        return;

    //Se testeaza daca memoria pentru matrice a fost alocata ...
    if(NULLMemTest(Matrix))
    {
        NrLin = NrCol = 0;
        State = Destroyed;
        return;
    }

    int **MatrixTemp=Matrix;
    //Se sterge memoria pe linii ...
    for(int contlin = 0; contlin < NrLin; contlin++)
    {
       //Se testeaza daca a fost alocata memorie pentru linia curenta ...
        if(NULLMemTest(*MatrixTemp))
                break;
        delete []*MatrixTemp; //Se sterge memoria pentru linia curenta ...
        *MatrixTemp++;

    }
    delete []Matrix;
    Matrix = nullptr;
    NrLin = NrCol = 0;
    State = Destroyed;
}

MatrixInt2::~MatrixInt2(void)
{
    ClearAndDestroy();
}
