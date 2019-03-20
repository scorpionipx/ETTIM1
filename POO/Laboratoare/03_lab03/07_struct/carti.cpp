/*****************************
Structuri de date
Functia principala
carti.cpp
*****************************/

#include "Carti.hpp"
using namespace std;
void main()
{
    Carte Pachet[52]; 
    //Pachet este un sir de 52 de carti
    
    Init(Pachet);
    cout << "Pachetul de carti ordonat:" << endl;
    AfisarePachet(Pachet);
    Amestec(Pachet);
    cout <<endl <<"Pachetul de carti amestecat:"; 
    cout << endl;
    AfisarePachet(Pachet);
    _getch();
}
