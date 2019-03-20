#include <malloc.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#ifndef _MATRICIC1_INCLUDED_
#define _MATRICIC1_INCLUDED_

enum Boolean
{
    false = 0,
    true = 1
};

enum Error
{
    error = 0,
    success = 1
};

/*Testeaza daca valoarea pointerului este NULL.
Daca da returneaza True, altfel returneaza False.*/
int NULLMemTest(void *);

/*Testeaza daca valoarea pointerului este NULL.
Daca da returneaza True si afiseaza un mesaj, altfel returneaza False.*/
int AllocError(void *);

/*Aloca dinamic memorie pentu o matrice cu NrLin linii si NrCol coloane.
Returneaza error sau success.*/
int AllocMatrixInt2(int ***, int , int);

/*Elibereaza memoria alocata dinamic pentru o matrice.
Memoria poate fi alocata folosind malloc sau calloc !!!
Returneaza error sau success.*/
int FreeMatrixInt2(int ***, int);

/*Tipareste la consola matricea de intregi specificata.*/
void PrintMatrixInt2(int **, int , int);

#endif
