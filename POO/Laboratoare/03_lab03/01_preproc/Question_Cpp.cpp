/************************************************
Question_Cpp.cpp
Definitia functiei Question ...
************************************************/
#include "hello.hpp"
using namespace std;
//Care din cele doua variante ale functiei //Question va fi compilata ...
//#define QUESTION1
#define QUESTION2

//Parametri: pointer la caracter.
//Formuleaza intrebarea furnizata ca parametru si //returneaza o valoare diferita de zero
//in caz ca raspunsul este 'da' si zero in caz ca //raspunsul este nu.
#ifdef QUESTION1
int Question(char *Mesaj)
{
    int DaNu; //In C++ int este diferit de char !   
    //Functia toupper functioneaza cu int.
    cout << Mesaj << " (y/n)";
    do
    {
        //DaNu = toupper(getch());
        DaNu = toupper(fgetc(stdin));
        //DaNu = toupper(fgetc(stdin));
        /*
        //Are acelasi efect ...
        DaNu = getch();
        DaNu = toupper();
        */
    }
    while(DaNu != 'Y' && DaNu != 'N');
    cout << endl;
    if(DaNu == 'Y') //DaNu are valoarea Y sau N !
        return 1;
    else
        return 0;
}
#endif
#ifdef QUESTION2
int Question(char *Mesaj)
{
    int DaNu;
    cout << Mesaj << " (y/n)";
    while(1)
    {
        DaNu = toupper(_getch());
        if(DaNu == 'Y')
        {
            cout << endl;
            return 1;
        }
        if(DaNu == 'N')
        {
            cout << endl;
            return 0;
        }
    }
}
#endif
