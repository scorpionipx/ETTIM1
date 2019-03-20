/************************************************
Clasa Moto: Clasa derivata din clasa Auto.
************************************************/

#include "auto.hpp"

#ifndef _MOTO_INCLUDED_
#define _MOTO_INCLUDED_
using namespace std;
class Moto : public Auto
{
public:
        Moto(void);
        Moto(Moto const &M) : Auto(M) {};
        ~Moto() {};
        
        virtual void SetUp(void);
        virtual int Pornire(void);
        virtual int Accelerare(int);
        virtual int Croaziera(int);
        friend ostream & operator <<(ostream &, Moto &);
};

#endif
