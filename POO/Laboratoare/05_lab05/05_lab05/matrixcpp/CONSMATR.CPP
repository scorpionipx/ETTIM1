/************************************************
consmatr.cpp
************************************************/

#include "matrixcpp.hpp"

//Constructor implicit ...
MatrixInt2::MatrixInt2(void)
{
    State = Constructed;
    Matrix = nullptr;
    NrLin = NrCol = 0;
}

//Constructor de copiere ...
MatrixInt2::MatrixInt2(MatrixInt2 const &M)
{
    State = Constructed;
    Matrix = nullptr;
    NrLin = NrCol = 0;
    *this = M; //Se foloseste operatorul de atribuire ...
}

MatrixInt2::MatrixInt2(int NL, int NC)
{
    State = Constructed;
    Matrix = nullptr;
    NrLin = NrCol = 0;
    SetUp(NL, NC);
}



