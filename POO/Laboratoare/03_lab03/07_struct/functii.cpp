/*****************************
Structuri de date
functii.cpp
*****************************/
#include "carti.hpp"
using namespace std;

void Init(Carte* Pachetul)
//Initializeaza pachetul de carti
{
        int num;
        int j = 0;
            
        for (num=2; num<=14; num++)
          {
           Pachetul[j].Numar = num;
           Pachetul[j].Culoare = Inima;
           Pachetul[j+13].Numar = num;
           Pachetul[j+13].Culoare = Frunza;
           Pachetul[j+26].Numar = num;
           Pachetul[j+26].Culoare = Romb;
           Pachetul[j+39].Numar = num;
           Pachetul[j++ +39].Culoare= Trefla;                 
                }
};

void AfisarePachet(Carte *Pachetul)
//Afiseaza toate cartile din pachet
{
        for(int j=0; j<52; j++)
        {
            AfisareCarte(Pachetul[j]);
            cout << " ";
            if ( !((j+1)%13) )   cout << endl;
          //salt la rand nou la fiecare 13 carti
        }
};


void AfisareCarte(Carte c)
//Afiseaza o carte din pachet
{
    if(c.Numar>=2 && c.Numar<=10) cout << c.Numar;
    else switch(c.Numar)
        {
            case Jack: cout << "J"; break;
            case Dama: cout << "Q"; break;
            case Rege: cout << "K"; break;
            case As:   cout << "A"; break;
        }
    switch(c.Culoare)
        {
            case Inima:  cout << "i"; break;
            case Frunza: cout << "f"; break;
            case Romb:   cout << "r"; break;
            case Trefla: cout << "t"; break;
        }        
};

void Amestec(Carte *Pachetul)
/*Amesteca pachetul:
Fiecare carte este interschimbata cu o alta
din pachet aleasa in mod aleator */
{
  for (int j=0; j<52; j++)
  {
double i; 
i = double(rand())/(double)(RAND_MAX+1);
        int k = int (52*i);
        Carte Temp = Pachetul[j];
        Pachetul[j] = Pachetul[k];
        Pachetul[k] = Temp;
    }        
};
