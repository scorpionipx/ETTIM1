/************************************************
Clasa Auto: clasa de baza pur virtuala pentru derivarea claselor
care modeleaza tipuri de autovehicule.
Nu pot exista obiecte de tipul Auto !!!
************************************************/

#include <iostream>
#include <conio.h>

#ifndef _AUTO_INCLUDED_
#define _AUTO_INCLUDED_
using namespace std;
enum Fuel //Tip de combustibil ...
{
    Motorina,
    CO90,
    CO98
};

enum State //Rezultatul unei actiuni ...
{
    Error,
    Success
};

enum Motor
{
    Oprit,
    Pornit,
};

class Auto //Clasa de baza ...
{
protected:
        int               Stare; //Starea in care se afla auto ...
        int               VitezaMaxima; //Viteza maxima in Km/h ...
        int               Viteza; //Viteza instantanee ...
        int               Capacitate; //Capacitatea cilindrica ...
        Fuel             TipCombustibil;
        int               CantitateCombustibil; //Cantitatea de combustibil in litri
        void Print(ostream &);
        
public:
        //Constructor implicit.
        Auto(void) : Stare(Oprit), VitezaMaxima(0), Viteza(0), Capacitate(0),
                           TipCombustibil(CO98), CantitateCombustibil(0) {};
        //Constructor de copiere.
        Auto(Auto const &A) : Stare(A.Stare), VitezaMaxima(A.VitezaMaxima), Viteza(A.Viteza),
                                           Capacitate(A.Capacitate), TipCombustibil(A.TipCombustibil),
                                           CantitateCombustibil(A.CantitateCombustibil) {};
        virtual ~Auto() {};

        //Functie virtuala pentru initializare. Este utilizata in clasele derivate.
        virtual void SetUp(void);
        //Functie virtuala. Returneaza Error sau Success.
        virtual int Pornire(void);
        //Functie pur virtuala. Returneaza Error sau Success.
        //Parametrul reprezinta timpul in secunde cat dureaza accelerarea.
        virtual int Accelerare(int) = 0;
        //Functie pur virtuala. Returneaza Error sau Success.
        //Parametrul reprezinta timpul in ore cat dureaza croaziera.
        virtual int Croaziera(int) = 0;
};

#endif
