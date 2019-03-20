/************************************************
opermatr.cpp
************************************************/

#include "matrixcpp.hpp"

int & MatrixInt2::operator()(int i, int j)
{
    if(!State || i >= NrLin || i < 0 || j >= NrCol || j < 0 )
    {
        cout << "Eroare la apelarea operatorului (,)\n";
        return State;
    }
    return Matrix[i][j];
}

MatrixInt2 & MatrixInt2::operator =(MatrixInt2 const &M) //
{
    if(!M.State)
    {
        ClearAndDestroy();
        return *this;
    }
    ClearAndDestroy(); //Este distrusa vechea matrice ...
    Copy(M); //Vechea matrice este inlocuita cu o copie a argumentului ...
    return *this;
}

MatrixInt2 & MatrixInt2::operator +=(MatrixInt2 const &M)
{
    if(!M.State) //Matricea M nu exista ...
        return *this;
    int MustChange = 0;
    int NrLinTemp, NrLinTempPrim;
    int NrColTemp, NrColTempPrim;
    NrLinTemp = NrLinTempPrim = M.NrLin;
    NrColTemp = NrColTempPrim = M.NrCol;
    if(NrLin > NrLinTemp)
    {
        NrLinTemp = NrLin;
        MustChange = 1;
    }
    if(NrCol > NrColTemp)
    {
        NrColTemp = NrCol;
        MustChange = 1;
    }
    if(MustChange) //Daca dimensiunile matricii originale nu sunt cele adecvate ..
    {
        MatrixInt2 MatrixInt2Temp(*this); //Se realizeaza o copie temporara a obiectului curent ...
        ClearAndDestroy(); //Se distruge obiectul curent ...
        if(!SetUp(NrLinTemp, NrColTemp)) //Se redimensioneaza obiectul curent ...
                return *this;
        //Se refac valorile matricii originale in noua matrice (mai mare) ...
        int **MatrixTemp=MatrixInt2Temp.Matrix;
        for(int contorlin = 0; contorlin < NrLin; contorlin++)
            for(int contorcol = 0; contorcol < NrCol; contorcol++)
                    Matrix[contorlin][contorcol] = MatrixTemp[contorlin][contorcol];
        //Se initializeaza cu 0 valorile din zonele bordate ...
        for(int contorlin = 0; contorlin < NrLin; contorlin++)
            for(int contorcol = NrCol; contorcol < NrColTemp; contorcol++)
                Matrix[contorlin][contorcol] = 0;
         for(int contorlin = NrLin; contorlin < NrLinTemp; contorlin++)
              for(int contorcol = 0; contorcol < NrColTemp; contorcol++)
                Matrix[contorlin][contorcol] = 0;
    }
    int **MTemp=M.Matrix;
    for(int contorlin = 0; contorlin < NrLinTempPrim; contorlin++)
        for(int contorcol = 0; contorcol < NrColTempPrim; contorcol++)
                Matrix[contorlin][contorcol] += MTemp[contorlin][contorcol];
    return *this;
}

MatrixInt2 & MatrixInt2::operator *=(int Scalar)
{
    for(int contorlin = 0; contorlin < NrLin; contorlin++)
        for(int contorcol = 0; contorcol < NrCol; contorcol++)
                Matrix[contorlin][contorcol] *= Scalar;
    return *this;
}

MatrixInt2 MatrixInt2::operator +(MatrixInt2 const &M)
{
    if(!M.State)
        return *this;
    MatrixInt2          MatrixResult(*this); //Matrice rezultat initializata cu valoarea matricii curente ...
    MatrixResult += M; //Operator binecunoscut ...
    return MatrixResult; //Se intoarce rezultatul adunarii ...
}

MatrixInt2 MatrixInt2::operator *(int Scalar)
{
    MatrixInt2 MatrixInt2Temp(NrLin, NrCol);
    int **MatrixTemp=MatrixInt2Temp.Matrix;
    for(int contorlin = 0; contorlin < NrLin; contorlin++)
        for(int contorcol = 0; contorcol < NrCol; contorcol++)
                MatrixTemp[contorlin][contorcol] = Matrix[contorlin][contorcol] * Scalar;
    return MatrixInt2Temp;
}

int MatrixInt2::operator ==(MatrixInt2 const &M)
{
    if(NrLin != M.NrLin && NrCol != M.NrCol)
        return false;

    int **MatrixTemp=M.Matrix;
    for(int contorlin = 0; contorlin < NrLin; contorlin++)
        for(int contorcol = 0; contorcol < NrCol; contorcol++)
                if(Matrix[contorlin][contorcol] != MatrixTemp[contorlin][contorcol])
                        return false;
    return true;
}
