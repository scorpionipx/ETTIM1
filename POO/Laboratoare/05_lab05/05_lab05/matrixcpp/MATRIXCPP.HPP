/************************************************
matrixcpp.hpp
************************************************/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctype.h>
using namespace std;

#ifndef _MATRIXCPP3_INCLUDED_
#define _MATRIXCPP3_INCLUDED_

/*
//Nu este nevoie de ele decat in versiuni mai vechi ...
enum Boolean
{
    false = 0,
    true = 1
};
*/

enum Error
{
    error = 0,
    success = 1
};

enum ObjState
{
    Destroyed = 0,
    Constructed = 1,
    LU = 2,
};


//Declaratia de clasa ...
class MatrixInt2
{
private:
    int State; //Starea curenta a obiectului ... 
    int **Matrix;
    int NrLin;
    int NrCol;
protected:
    void Copy(MatrixInt2 const &); //Realizeaza copierea ...
public:
    MatrixInt2(void); //Constructor implicit ...
    MatrixInt2(MatrixInt2 const &); //Constructor de copiere ...
    MatrixInt2(int, int); //Constructor ...
    ~MatrixInt2(void); //Destructor ...
    void ClearAndDestroy(void);
    int SetUp(int, int); //Returneaza starea de eroare ...
    
    void Print(ostream & = cout, int = 3) const; //Tipareste matricea la consola ...
    friend ostream & operator <<(ostream &, MatrixInt2 const &);

    int & operator()(int, int); //Operator de acces aleatoriu ...
    MatrixInt2 & operator =(MatrixInt2 const &); //Operator de atribuire ...
    MatrixInt2 & operator +=(MatrixInt2 const &); //Operator de adunare ...
    MatrixInt2 & operator *=(int); //Operator de inmultire cu scalar intreg ...
    MatrixInt2 operator +(MatrixInt2 const &); //Operator de adunare ...
    MatrixInt2 operator *(int); //Operator de inmultire ...

    int operator ==(MatrixInt2 const &); //Operator relational ...

    int GetNrLin(void) {return NrLin;}
    int GetNrCol(void) {return NrCol;}
    int ** GetMatrix(void) {return Matrix;}
};

/*Testeaza daca valoarea pointerului este nullptr.
Daca da returneaza True, altfel returneaza False.*/
int NULLMemTest(void *);

/*Testeaza daca valoarea pointerului este nullptr.
Daca da returneaza True si afiseaza un mesaj, altfel returneaza False.*/
int AllocError(void *);

#endif
