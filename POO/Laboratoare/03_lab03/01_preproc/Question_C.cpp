/************************************************
Definitia functiei Question ...
************************************************/
#include "hello.hpp"

//Parametri: pointer la caracter.
//Formuleaza intrebarea furnizata ca parametru si returneaza o valoare diferita de zero
//in caz ca raspunsul este 'da' si zero in caz ca raspunsul este nu.
int Question(char *Mesaj)
{
    int DaNu; //In C++ int este diferit de char !!! Functia toupper functioneaza cu int.
    printf(Mesaj);
    puts(" (y/n)");
    do
    {
        DaNu = toupper(getch());
        //DaNu = toupper(fgetc(stdin));
        /*
        //Are acelasi efect ...
        DaNu = getch();
        DaNu = toupper();
        */
    }
    while(DaNu != 'Y' && DaNu != 'N');
    if(DaNu == 'Y') //DaNu are valoarea Y sau N !!!
        return 1;
    else
        return 0;
}


