/*****************************
Supraincarcarea functiilor
addsir.cpp
*****************************/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;
void adunsir(char *s1, char *s2);
void adunsir(char *s1, int i);

int main()
{
    char sir [80];

    strcpy(sir, "Functii ");
    adunsir(sir, "supraincarcate ");
    cout << sir << "\n";

    adunsir(sir, 100);
    cout << sir << endl;

    _getch();
    return 0;
}

//Functia concateneaza doua siruri
void adunsir(char *s1, char *s2)
{
    strcat(s1, s2);
}

//Functia concateneaza un sir cu un intreg "sir"
void adunsir (char *s1, int i)
{
    char temp[80];

    sprintf(temp, "%d", i);
    strcat(s1,temp);
}
