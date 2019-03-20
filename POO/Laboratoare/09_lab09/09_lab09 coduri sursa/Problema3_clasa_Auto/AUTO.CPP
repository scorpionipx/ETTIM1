/************************************************
Clasa Auto: clasa de baza pur virtuala pentru derivarea claselor
care modeleaza tipuri de autovehicule.
Nu pot exista obiecte de tipul Auto !!!
************************************************/
#include <iostream>
#include "auto.hpp"
using namespace std;
//Functie virtuala pentru initializare. Este utilizata in clasele derivate.
 void Auto::SetUp(void)
{
    cout << "Viteza initiala de croaziera: ";
    cin >> Viteza;
    cout << "Numarul de litri de combustibil la alimentare: ";
    cin >> CantitateCombustibil; 
}


 int Auto::Pornire(void)
{
    if(Stare == Pornit)
    {
        cout << "Deja pornit ..." << endl;
        return Success;
    }
    if(CantitateCombustibil <= 0)
    {
        cout << "Rezervor gol !!!" << endl;
        return Error;
    }
    Stare = Pornit;
    return Success;
}

void Auto::Print(ostream &Out)
{
    switch(Stare)
    {
        case Pornit:
                Out << "Pornit" << endl;
                break;
        case Oprit:
                Out << "Oprit" << endl;
                break;
    }
    Out << "Viteza maxima: " << VitezaMaxima << "km/h" << endl;
    Out << "Viteza de croaziera: " << Viteza << "km/h" << endl;
    Out << "Capacitate cilindrica: " << Capacitate << "cmc" << endl;
    Out << "Tip combustibil: ";
    switch(TipCombustibil)
    {
        case Motorina:
                Out << "Motorina" << endl;
                break;
        case CO90:
                Out << "Benzina cu CO 90" << endl;
                break;
        case CO98:
                Out << "Benzina cu CO 98" << endl;
                break;
    }
    cout << "Cantitatea de combustibil din rezervor: " << CantitateCombustibil << " l." << endl;
}
