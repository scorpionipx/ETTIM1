/************************************************
Clasa Truck: Clasa derivata din clasa Auto.
************************************************/

#include "auto.hpp"

#ifndef _TRUCK_INCLUDED_
#define _TRUCK_INCLUDED_
using namespace std;
class Truck : public Auto
{
protected:
        int             Remorca; //Numarul de remorci ...
public:
        Truck(void);
        Truck(Truck const &T) : Auto(T), Remorca(T.Remorca) {};
        ~Truck() {};
        
        virtual void SetUp(void);
        virtual int Pornire(void);
        virtual int Accelerare(int);
        virtual int Croaziera(int);
        friend ostream& operator <<(ostream &, Truck &);
};

#endif
