#include "truck.hpp"
#include "moto.hpp"
#include "limo.hpp"
#include <iostream>
using namespace std;
int main(void)
{
    Auto *Automobile[3]; //Vector de pointeri la obiecte de tipul Auto ...
    Truck T;
    Moto M;
    Limo L;
    Automobile[0] = &T;
    Automobile[1] = &M;
    Automobile[2] = &L;
    int Contor;
    int Timp;
    for(Contor = 0; Contor < 3; Contor++)
    {
        if(!Automobile[Contor]->Pornire())
            cout << "Probleme cu automobilul " << Contor << endl;
        getch();
    }
    cout << "Timpul de accelerare ? (secunde) ";
    cin >> Timp;
    for(Contor = 0; Contor < 3; Contor++)
    {
        if(!Automobile[Contor]->Accelerare(Timp))
            cout << "Probleme cu automobilul " << Contor << endl;
        getch();
    }
    cout << T;
    getch();
    cout << M;
    getch();
    cout << L;
    getch();
    cout << "Timpul de croaziera ? (ore) ";
    cin >> Timp;
    for(Contor = 0; Contor < 3; Contor++)
    {
        if(!Automobile[Contor]->Croaziera(Timp))
            cout << "Probleme cu automobilul " << Contor << endl;
        getch();
    }
    cout << T;
    getch();
    cout << M;
    getch();
    cout << L;
    getch();

    /*
    //Utilizare gresita a pointerului la obiect de tip clasa de baza caruia i s-a atribuit adresa
    //unui obiect din clasa derivata.
    for(Contor = 0; Contor < 3; Contor++)
    {
        cout << *(Automobile[Contor]);
        getch();
    }
    */
	cout<<"\nApasati o tasta...";
    return 0;
}
