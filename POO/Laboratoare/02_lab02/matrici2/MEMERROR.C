#include "matrixc2.h"

/*Testeaza daca valoarea pointerului este NULL.
Daca da returneaza True, altfel returneaza False.*/
int NULLMemTest(void *Ptr)
{
    if(!Ptr)
        return true;
    return false;
}

/*Testeaza daca valoarea pointerului este NULL.
Daca da returneaza True si afiseaza un mesaj, altfel returneaza False.*/
int AllocError(void * Ptr)
{
    if(NULLMemTest(Ptr))
    {
        puts("Eroare la alocarea memoriei ...\n");
        return true;
    }
    return false;
}


