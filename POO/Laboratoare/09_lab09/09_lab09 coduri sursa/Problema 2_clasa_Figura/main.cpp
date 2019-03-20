
#include <iostream>
#include <conio.h>
#include "figuri.hpp"

using namespace std;

int main()
   {
   const int N = 3;    // nr. de figuri

   Figura* tabpfig[N] = { &Bol(10, 0, 3), &Patrat(20, 1, 5),&Triunghi(30, 1, 7) };
   cout << endl << endl;    
   for(int j=0; j<N; j++)   // afiseaza cele 3 figuri
      tabpfig[j]->deseneaza();
   cout<<"\nApasati o tasta...";
    _getch();
	return 0;
   }
