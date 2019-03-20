/************************************************
Clasa Moto: Clasa derivata din clasa Auto.
************************************************/
#include <iostream>
#include "moto.hpp"
using namespace std;
Moto::Moto()
{
    SetUp();
}

 void Moto::SetUp(void)
{
    cout << "Moto" << endl;
    VitezaMaxima = 160;
    Capacitate = 1400;
    TipCombustibil = CO90;
    Auto::SetUp(); //Apel la functia din clasa de baza ...
}

 int Moto::Pornire(void)
{
    cout << "Moto :" << endl << "Incerc sa pornesc" << endl << "BRRrrrr BRRrrrr" << endl;
    if(Auto::Pornire())
    {
        cout << "Brm Tic Tic Tic Brm Tic Tic Tic Brm Tic Tic Tic" << endl;
        return Success;
    }
    cout << "Chhh Chhh" << endl;
    return Error;
}

 int Moto::Accelerare(int Timp)
{
    cout << "Moto:";
    if(Stare == Pornit && CantitateCombustibil > 0)
    {
        cout << "Accelerez .........." << endl;
        if((Viteza += 20 * Timp) > VitezaMaxima)
                Viteza = VitezaMaxima;
        return Success;
    }
    cout << "Moto : SSSSssss ...." << endl;
    Stare = Oprit;
    return Error;
}

 int Moto::Croaziera(int Timp)
{
    cout << "Moto :" << endl;
    if(Stare == Oprit)
    {
        cout << "SSSSssss ...." << endl;
        return Error;
    }
    for(int Contor = 0; Contor < Timp; Contor++)
    {
        if(CantitateCombustibil > 0)
                cout << "RRRRRrrrrrrrrrrrrrrrrr" << endl;
        else
        {
            cout << "Rezervor gol !!!" << endl;
            CantitateCombustibil = 0;
            return Error;
        }
        CantitateCombustibil -= 3;
    }
    return Success;
}

ostream & operator <<(ostream &Out, Moto &M)
{
    Out << "Moto :" << endl;
    M.Print(Out);
    return Out;
}
