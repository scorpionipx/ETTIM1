/************************************************
Clasa Truck: Clasa derivata din clasa Auto.
************************************************/
#include <iostream>
#include "truck.hpp"
using namespace std;
Truck::Truck()
{
    SetUp();
}

 void Truck::SetUp(void)
{
    cout << "Truck :" << endl;
    VitezaMaxima = 120;
    Capacitate = 4000;
    TipCombustibil = Motorina;
    Auto::SetUp(); //Apel la functia din clasa de baza ...
    cout << "Numar remorci: ";
    cin >> Remorca;
    if(Remorca < 0)
        Remorca = 0;
}

 int Truck::Pornire(void)
{
    cout << "Truck :" << endl << "Incerc sa pornesc ..." << endl << "BRRrrrr" << endl;
    if(Auto::Pornire())
    {
        cout << "Brm Brm Brm" << endl;
        return Success;
    }
    cout << "Chhh Chhh" << endl;
    return Error;
}

 int Truck::Accelerare(int Timp)
{
    cout << "Truck :";
    if(Stare == Pornit && CantitateCombustibil > 0)
    {
        cout << "Accelerez .........." << endl;
        if((Viteza += 5 * Timp) > VitezaMaxima)
                Viteza = VitezaMaxima;
        return Success;
    }
    cout << "SSSSssss ...." << endl;
    Stare = Oprit;
    return Error;
}

 int Truck::Croaziera(int Timp)
{
    cout << "Truck :" << endl;
    if(Stare == Oprit)
    {
        cout << "SSSSssss ...." << endl;
        return Error;
    }
    for(int Contor = 0; Contor < Timp; Contor++)
    {
        if(CantitateCombustibil > 0)
                cout << "Brm Brm Brm" << endl;
        else
        {
            cout << "Rezervor gol !!!" << endl;
            CantitateCombustibil = 0;
            return Error;
        }
        CantitateCombustibil -= 10 + 2 * Remorca;
    }
    return Success;
}

ostream & operator <<(ostream &Out, Truck &T)
{
    Out << "Truck :" << endl;
    T.Print(Out);
    cout << "Numar de remorci: " << T.Remorca << endl;
    return Out;
}
