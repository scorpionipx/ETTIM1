/*****************************
Parametri Impliciti
salut.cpp
*****************************/

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

//Atentie la spatiul dintre * si = :
void Afis(char *Sir0, char *, char * ="studentule", char * ="!");
//Ultimii 2 parametri sunt impliciti

//Este gresita varianta de mai jos?
//void Afis(char *Sir0, char *Sir1, char *Sir2="studentule", char *Sir3="!");

//Ce greseala sesizati in varianta urmatoare?
//void Afis(char *Sir0, char *Sir1, char *Sir2="studentule", char *Sir3);

void main()
{
    char Nume[20];

    cout << "Introduceti un nume: ";
    cin >> Nume;
    cout << endl;

    Afis("0-> ","Salut ");
    Afis("1-> ","Salut ",Nume);
    Afis("2-> ","Spor la lucru, ");
    Afis("3-> ","Iti place C++, ",Nume,"?");
    
    //Apeluri incorecte:
    //Afis("4-> ",);
    //Afis("5-> ","Iti place C++, ", ,"?");

    _getch();    
}

void Afis(char *Sir0, char *Sir1, char *Sir2, char *Sir3)
{
    cout << Sir0 << Sir1 << Sir2 << Sir3 <<endl;
}
