/************************************************
Hello.hpp
Declaratii si directive #include ...
************************************************/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>


#ifndef _HELLO_INCLUDED_
#define _HELLO_INCLUDED_

//#define IO_C
#define IO_CPP

//Prototipuri de functii ...

//Parametri: pointer la caracter.
//Tipareste mesajul parametru.
void PrintMessage(char *);

//Parametri: pointer la caracter.
//Formuleaza intrebarea furnizata ca parametru si //returneaza o valoare diferita de zero
//in caz ca raspunsul este 'da' si zero in caz ca //raspunsul este nu.
int Question(char *);

#endif
