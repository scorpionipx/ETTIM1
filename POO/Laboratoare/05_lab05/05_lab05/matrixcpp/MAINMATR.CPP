/************************************************
mainmatr.cpp
************************************************/

#include "matrixcpp.hpp"

void main(void)
{
    MatrixInt2 Matrix1, Matrix2;

    int NrLin, NrCol;

    cout << "Introduceti numarul de linii: ";
    cin >> NrLin;

    cout << "Introduceti numarul de coloane: ";
    cin >> NrCol;

    Matrix1.SetUp(NrLin, NrCol);
    
    Matrix1.Print(); //Matricea nu a fost initializata ...

    for(int contlin = 0; contlin < Matrix1.GetNrLin(); contlin++)
        for(int contcol = 0; contcol < Matrix1.GetNrCol(); contcol++)
                Matrix1(contlin, contcol) = contlin + contcol;
    Matrix1.Print();
	Matrix2 = Matrix1;
    cout << "Relatia intre cele doua matrici este: " << (Matrix2 == Matrix1) << endl;
    Matrix2.Print();
    MatrixInt2 Matrix3(Matrix2);
    Matrix1.ClearAndDestroy();
    Matrix3.Print();
    Matrix2 += Matrix3;
    Matrix2.Print();
    Matrix3 *= 100;
    Matrix3.Print(cout, 5);
    MatrixInt2 Matrix4;
    Matrix4 = Matrix2 + Matrix3;
    Matrix4.Print(cout, 5);
    MatrixInt2 Matrix5;
    Matrix5 = Matrix4 * 100;
    Matrix5.Print(cout, 8);
    cout << Matrix5 << "Gata ... pentru moment ..." << endl;
    Matrix3 = Matrix4 = Matrix5 + Matrix2;
    cout << Matrix3 << Matrix4 << Matrix5 + Matrix2 << "Gata ..." << endl;

}
