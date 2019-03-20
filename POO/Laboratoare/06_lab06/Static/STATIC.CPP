#include <iostream>
#include <conio.h>
 
using namespace std;

class Clasa
{
private:
        static int      NumarObiecte; //Contor pentru numar de obiecte
        int               ValInt; //Valoare intreaga

public:
        static void PrintNumarObiecte(void);
        Clasa(void);
        Clasa(Clasa const &);
        Clasa(int);
        ~Clasa();
        Clasa & operator =(Clasa const &); //Supradefinirea operatorului de atribuire ...
        //Supradefinirea operatorului + ... .
        //Operatorul membru va fi mostenit in clasele derivate.
        Clasa operator +(Clasa &);
        //Supradefinirea operatorului - ...
        //Operatorul "prieten" nu va fi mostenit in clasele derivate.
        friend Clasa operator -(Clasa &, Clasa &);
        //Supradefinirea operatorului de insertie.
        friend ostream & operator <<(ostream &, Clasa &);
        //Supradefinirea operatorului de extractie.
        friend istream & operator >>(istream &, Clasa &);
};

int Clasa::NumarObiecte = 0; //initializarea obiectului membru static ...

Clasa::Clasa(void)
{
    NumarObiecte++; //Este creeat un nou obiect ...
    ValInt = 0;
    PrintNumarObiecte();
}

Clasa::Clasa(Clasa const &Obiect)
{
    NumarObiecte++; //Este creeat un nou obiect ...
    ValInt = Obiect.ValInt;
    PrintNumarObiecte();
}

Clasa::Clasa(int Val)
{
    NumarObiecte++; //Este creeat un nou obiect ...
    ValInt = Val;
    PrintNumarObiecte();
}

Clasa::~Clasa()
{
    NumarObiecte--; //Este distrus un obiect
    PrintNumarObiecte();
}

void Clasa::PrintNumarObiecte(void)
{
    cout << "Numarul curent de obiecte este:" << NumarObiecte << endl;
}

Clasa & Clasa::operator =(Clasa const &Obiect)
{
    ValInt = Obiect.ValInt;
    return *this;
}

Clasa Clasa::operator +(Clasa &Obiect)
{
    Clasa Rezultat;
    Rezultat.ValInt = ValInt + Obiect.ValInt;
    return Rezultat;
}

Clasa operator -(Clasa &Obiect1, Clasa &Obiect2)
{
    Clasa Rezultat;
    Rezultat = Obiect1.ValInt - Obiect2.ValInt;
    return Rezultat;
}

ostream & operator <<(ostream &Out, Clasa &Obiect)
{
    Out << Obiect.ValInt;
    return Out;
}

istream & operator >>(istream &In, Clasa &Obiect)
{
    In >> Obiect.ValInt;
    return In;
}

void main(void)
{
    Clasa Obiect1;
    cout << "Introduceti o valoare intreaga: ";
    cin >> Obiect1;
    Clasa Obiect2;
    cout << "Introduceti o valoare intreaga: ";
    cin >> Obiect2;
    Clasa Obiect3 = Obiect1; //Este apelat constructorul de copiere ...
    Clasa *PtrObiect; //Pointer la obiect de tipul Clasa ...
    //Se aloca memorie dinamica pentru un obiect.
    //Pentru initializare se foloseste constructorul de copiere.
    PtrObiect = new Clasa(Obiect3);//Se aloca memorie dinamica pentru un obiect
    if(!PtrObiect)
    {
        cout << "Eroare la alocarea dinamica de memorie !!!" << endl;
        return;
    }
     *PtrObiect = Obiect1 + Obiect2;
     cout << Obiect1<< " + " << Obiect2 << " = " << *PtrObiect;
	 cout<<endl<<"Apasati o tasta pentru a continua..."<<endl;
     _getch();
     delete PtrObiect;
     Obiect3 = Obiect1 - Obiect2;
     cout << Obiect1<< " - " << Obiect2 << " = " << Obiect3;
	 cout<<endl<<"Apasati o tasta pentru a continua..."<<endl;
     _getch();
     Clasa::PrintNumarObiecte(); //Apelul functiei declarata static ...
     //Se aloca memorie dinamica pentru 10 obiecte de tipul clasa ...
     PtrObiect = new Clasa[10];
     if(!PtrObiect)
     {
         cout << "Eroare la alocarea memoriei dinamice !!!" << endl;
         return;
     }
     delete []PtrObiect;
     //delete PtrObiect; //Varianta gresita. De ce ?
    }
