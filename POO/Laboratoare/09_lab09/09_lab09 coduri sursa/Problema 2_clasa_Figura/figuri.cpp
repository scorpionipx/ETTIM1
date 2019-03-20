#include <conio.h>
#include <iostream>
#include "figuri.hpp"
using namespace std;
////////////////////////////////////////////////////////////////

void Figura::jos() const        // muta cursorul in jos pana la inceputul figurii
   {
   for(int y=0; y<yCo; y++)
      cout << endl;
   }
////////////////////////////////////////////////////////////////

void Patrat::deseneaza() const       // deseneaza un patrat
   {
   Figura::jos();               // pozitioneaza y la inceputul figurii
   for(int y=0; y<getz(); y++)  // deplaseaza y in jos pt. a desena figura
      {
      int x;
      for(x=1; x<getx(); x++)   // spatii pana la inceputul figurii
         cout << ' ';
      for(x=0; x<getz(); x++)   // deseneaza o linie de X-uri
         cout << 'X';
      cout << endl;
      }
   }
////////////////////////////////////////////////////////////////

void Triunghi::deseneaza() const                    // deseneaza triunghi
   {
   Figura::jos();
   for(int y=0; y<getz(); y++)
      {
      int x;
      for(x=0; x < getx()-y+1; x++)
         cout << ' ';
      for(x=0; x<2*y+1; x++)
         cout << 'X';
      cout << endl;
      }
   }
////////////////////////////////////////////////////////////////

void Bol::deseneaza() const         // deseneaza triunghi cu varful in jos
   {
   Figura::jos();
   for(int y=0; y<getz(); y++)
      {
      int x;
      for(x=0; x < getx()-(getz()-y)+2; x++)
         cout << ' ';
      for(x=0; x < 2*(getz()-y)-1; x++)
         cout << 'X';
      cout << endl;
      }
   }
///////////////////////////////////////////////////////////////////
