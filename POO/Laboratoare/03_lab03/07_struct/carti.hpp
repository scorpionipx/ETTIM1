/*****************************
Structuri de date:
Declaratii si incluziuni
carti.hpp
*****************************/

#include <iostream>
#include <stdlib.h>
#include <conio.h>

enum Culori {Inima, Frunza, Romb, Trefla};
struct Carte
        {
            int Numar;
            Culori Culoare;
        };

const int Jack = 11;
const int Dama = 12;
const int Rege = 13;
const int As = 14;

void Init(Carte *Pachetul); 
//Initializarea pachetului
void AfisareCarte(Carte c);
void AfisarePachet(Carte *Pachetul);
void Amestec(Carte *Pachetul); 
//Amesteca pachetul
