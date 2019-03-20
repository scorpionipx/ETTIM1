/************************************************
Clasa Limo: Clasa derivata din clasa Auto.
************************************************/

#include "auto.hpp"

#ifndef _LIMO_INCLUDED_
#define _LIMO_INCLUDED_
using namespace std;
class Limo : public Auto
{
protected:
        int             Locuri; //Numarul de locuri ...
public:
        Limo(void);
        Limo(Limo const &L) : Auto(L), Locuri(L.Locuri) {};
        ~Limo() {};
        
        virtual void SetUp(void);
        virtual int Pornire(void);
        virtual int Accelerare(int);
        virtual int Croaziera(int);
        friend ostream & operator <<(ostream &, Limo &);
};

#endif
