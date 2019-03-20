/************************************************
prntmatr.cpp
************************************************/

#include "matrixcpp.hpp"

/*Tipareste la consola matricea de intregi specificata.*/
void MatrixInt2::Print(ostream &StrOut, int Width) const
{
    StrOut << "Sa afisez matricea ? (y/n)";
    int Test;
    do
    {
        Test = toupper(cin.get());
    }
    while(Test != 'Y' && Test != 'N');

    if(Test == 'Y')
    {
        StrOut << "Matricea este :\n";
        for(int contorlin = 0; contorlin < NrLin; contorlin++)
        {
            for(int contorcol = 0; contorcol < NrCol; contorcol++)
                    StrOut << setw(Width) << Matrix[contorlin][contorcol];
            StrOut << endl;
        }
    }
}

ostream & operator <<(ostream &StrOut, MatrixInt2 const &M)
{
    M.Print(StrOut,8);
    return StrOut;
}
