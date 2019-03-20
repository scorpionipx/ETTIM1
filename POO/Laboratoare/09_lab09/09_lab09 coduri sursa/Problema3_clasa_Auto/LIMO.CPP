/************************************************
Clasa Limo: Clasa derivata din clasa Auto.
************************************************/
#include <iostream>
#include "limo.hpp"
using namespace std;
Limo::Limo()
{
    SetUp();
}

 void Limo::SetUp(void)
{
    cout << "Limo" << endl;
    VitezaMaxima = 220;
    Capacitate = 1600;
    TipCombustibil = CO98;
    Locuri = 5;
    Auto::SetUp(); //Apel la functia din clasa de baza ...
}

 int Limo::Pornire(void)
{
    cout << "Limo :" << endl << "Incerc sa pornesc" << endl << "Bzzzz" << endl;
    if(Auto::Pornire())
    {
        cout << "TicTicTicTicTic" << endl;
        return Success;
    }
    cout << "Chhh Chhh" << endl;
    return Error;
}

 int Limo::Accelerare(int Timp)
{
    cout << "Limo:";
    if(Stare == Pornit && CantitateCombustibil > 0)
    {
        cout << "Accelerez .........." << endl;
        if((Viteza += 40 * Timp) > VitezaMaxima)
                Viteza = VitezaMaxima;
        return Success;
    }
    cout << "Limo : SSSSssss ...." << endl;
    Stare = Oprit;
    return Error;
}

 int Limo::Croaziera(int Timp)
{
    cout << "Limo :" << endl;
    if(Stare == Oprit)
    {
        cout << "SSSSssss ...." << endl;
        return Error;
    }
    for(int Contor = 0; Contor < Timp; Contor++)
    {
        if(CantitateCombustibil > 0)
                cout << "ZZZZZZZzzzzzzzzzzzzzzzz" << endl;
        else
        {
            cout << "Rezervor gol !!!" << endl;
            CantitateCombustibil = 0;
            return Error;
        }
        CantitateCombustibil -= 7;
    }
    return Success;
}

ostream & operator <<(ostream &Out, Limo &L)
{
    Out << "Limo :" << endl;
    L.Print(Out);
    cout << "Numar de locuri: " << L.Locuri << endl;
    return Out;
}
