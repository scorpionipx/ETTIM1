#include <iostream>
#include <conio.h>
using namespace std; //se asigura vizibilitatea spatiului de nume std
//Starea in care se poate afla un obiect ... .
enum State
{
    Distrus = 0,
    Construit = 1,
    SetUpCompleted = 3
    //Alte stari pe care le poate avea obiectul ... .
};

//Starea de eroare pe care o poate
enum Error
{
    success = 0,
    error = 1
    //Alte stari de eroare ... .
};

class Clasa2
{
private:
        int     StareObiect; //Stare obiectului ... .
        int    *PtrIntPrivate; //Vector de intregi ... .
        int     Dim; //Dimensiunea vectorului de intregi ... .
        
public:
        Clasa2(void); //Constructor implicit ... .
        Clasa2(const Clasa2&); //Constructor de copiere ... .
        Clasa2(int); //Constructor cu parametru dimensiunea vectorului de intregi ... .
        ~Clasa2(); //Destructor ... .

        void ClearAndDestroy(void); //Functie pentru distrugerea explicita a unui obiect ... .
        int SetUp(int); //Functie pentru reconstruirea explicita a unui obiect ... .
        int Copy(Clasa2 const &); //Copierea obiectului parametru ... .

        void ScanCon(void); //Citirea valorilor de la cosola ... .
        void PrintCon(void); //Afisarea valorilor la consola ... .
};

Clasa2::Clasa2(void)
{
    StareObiect = Construit;
    PtrIntPrivate = nullptr;
    Dim = 0;
}

Clasa2::Clasa2(const Clasa2& C)
{
    //De ce asa ?
    StareObiect = Distrus;
    PtrIntPrivate = nullptr;
    Copy(C);
}

Clasa2::Clasa2(int Dim)
{
    StareObiect = Distrus;
    SetUp(Dim);
}

Clasa2::~Clasa2()
{
    ClearAndDestroy();
}

//Are grija sa nu distruga efectiv de doua ori consecutiv acelasi obiect.
//Aceasta previne printre altele eliberarea unei zone de memorie deja eliberata.
void Clasa2::ClearAndDestroy(void)
{
    if(!StareObiect) //Daca obiectul este deja distrus ....
        return;
    StareObiect = Distrus;
    if(!PtrIntPrivate)
        return;
    delete []PtrIntPrivate; //Este eliberata zona de memorie corespunzatoare vectorului ....
    PtrIntPrivate = nullptr; //Obicei bun ... 
}

int Clasa2::Copy(Clasa2 const &C)
{
    if(StareObiect)
        ClearAndDestroy(); //Este distrus explicit obiectul curent ... .
    if(!C.StareObiect)
        return success;

    StareObiect = C.StareObiect;
    Dim = C.Dim;
    if(!Dim)
    {
        PtrIntPrivate = nullptr;
        return success;
    }
    PtrIntPrivate = new int[Dim]; //Alocare dinamica a memoriei necesare pentru Dim int ... .
    if(!PtrIntPrivate)
        return error;

    //Copierea valorilor din obiectul sursa ... .
    for(int Contor = 0; Contor < Dim; Contor++)
        PtrIntPrivate[Contor] = C.PtrIntPrivate[Contor];

    /*
    //Sau cu aces direct prin pointer ... .
        int *PtrIntDest = PtrIntPrivate;
        int *PtrIntSursa = C.PtrIntPrivate;
        for(int Contor = 0; Contor < Dim; Contor++)
            *PtrIntDest++ = *PtrIntSursa++;
    */

    StareObiect = SetUpCompleted;
    return success;
}

int Clasa2::SetUp(int Dim)
{
    if(StareObiect)
        ClearAndDestroy(); //Este distrus explicit obiectul curent ... .

   //Se reconstruieste obiectul ... .
   Clasa2::Dim = Dim;
   PtrIntPrivate = new int[Dim];
   if(!PtrIntPrivate) //Nu s-a putut aloca memorie pentru Dim int ... .
   {
       StareObiect = Distrus;
       return error;
   }
   //S-a reusit alocare memoriei pentru Dim int ... .
   StareObiect = SetUpCompleted;
   return success;
}



void Clasa2::ScanCon(void)
{
    if(!StareObiect || !PtrIntPrivate)
    {
        cout << "Care este dimensiunea vectorului de intregi ? ";
        cin >> Dim;
        if(SetUp(Dim))
        {
            cout << "Completati mesajul in mod corespunzator !!!" << endl;
            return;
        }
    }
    cout << "Introduceti valorile intregi ale elementelor vectorului de "
           << Dim << " intregi:" << endl << "Indice\t\tvaloare" << endl;
    for(int Contor = 0; Contor < Dim; Contor++)
    {
        cout << Contor << " :\t\t";
        cin >> PtrIntPrivate[Contor];
    }
    return;
}

void Clasa2::PrintCon(void)
{
    if(!StareObiect)
    {
        cout << "Obiect neconstruit ..." << endl;
        return;
    }
    if(!PtrIntPrivate)
    {
        cout << "Vector vid ..." << endl;
        return;
    }
    cout << "Elementele vectorului de "
           << Dim << " intregi:" << endl << "Indice\t\tvaloare" << endl;
    for(int Contor = 0; Contor < Dim; Contor++)
    {
        cout << Contor << " :\t\t" << PtrIntPrivate[Contor] << endl;
    }
    cout << "Apasati o tasta pentru a continua ..." << endl;
    _getch();
}


void main(void)
{
    Clasa2 Obiect1;
    
    Obiect1.PrintCon();
    Obiect1.ScanCon();
    Obiect1.PrintCon();

    Clasa2 Obiect2(Obiect1);
    Obiect2.PrintCon();
    Obiect1.SetUp(10);
    
    Obiect1.PrintCon();
    Obiect1.ScanCon();
    Obiect1.ClearAndDestroy();
    Obiect1.PrintCon();
    Obiect1.Copy(Obiect2);
    Obiect1.PrintCon();
    Obiect2.PrintCon();
    
   
}
