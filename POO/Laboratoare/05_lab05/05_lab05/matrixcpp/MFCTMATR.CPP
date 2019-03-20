/************************************************
mfctmatr.cpp
************************************************/

#include "matrixcpp.hpp"

//Relizeaza o copie a matricii ...
void MatrixInt2::Copy(MatrixInt2 const &M)
{
    NrLin = M.NrLin;
    NrCol = M.NrCol;
    State = Constructed;
    if(!State)
    {
        Matrix = nullptr;
        return;
    }
    if(!SetUp(NrLin, NrCol))
        return;
    int **MatrixTemp=M.Matrix;
    for(int contorlin = 0; contorlin < NrLin; contorlin++)
        for(int contorcol = 0; contorcol < NrCol; contorcol++)
                Matrix[contorlin][contorcol] = MatrixTemp[contorlin][contorcol];
}

//Aloca dinamic memorie pentu o matrice cu NrLin linii si NrCol coloane.
//Returneaza error sau success.
int MatrixInt2::SetUp(int NrLin, int NrCol)
{
    if(State != Destroyed)
        ClearAndDestroy();
    State = Constructed;

    MatrixInt2::NrLin = NrLin;
    MatrixInt2::NrCol = NrCol;
    
    /*Se aloca memorie pentru pointeri la linii ...*/
    Matrix = new int *[NrLin]; //Se foloseste operatorul new (specific C++)
    if(AllocError(Matrix))
    {
        ClearAndDestroy();
        return error;
    }

    int ** MatrixTemp=Matrix; //Initializarea folosind sintaxa de la C++ (constructor de copiere) ...
    for(int contorlin = 0; contorlin < NrLin; (contorlin++, MatrixTemp++))
    {
        /*Se aloca memorie pentru o linie ...*/
        *MatrixTemp = new int[NrCol];
        if(AllocError(*MatrixTemp))
        {
            /*In caz de eroare la alocare se sterge memoria deja alocata ...*/
            ClearAndDestroy();
            return error;
        }
    }
    return success;
}

