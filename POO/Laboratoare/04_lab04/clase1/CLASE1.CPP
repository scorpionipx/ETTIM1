/************************************************
clase1.cpp
************************************************/

#include <iostream>
#include <conio.h>
#include <malloc.h>
//Compilare conditionata ...
//#define _APEL_METODA_

using namespace std; //se asigura vizibilitatea spatiului de nume std

//Declararea tipului de date Clasa1
class Clasa1
{
//Declararea membrilor clasei Clasa1
private:
        int             IntPrivate;
        double          DoublePrivate;
        const char     *Nume; //Sir constant de caractere care reprezinta numele obiectului...
                              //Sau pointer la char constant ...
        //Declararea functiilor membru private ale clasei Clasa1
        void Mesaj(char *);
                
protected:
        int          IntProtected;
        double       DoubleProtected;
        //Declararea functiilor membru protected ale clasei Clasa1
        void PrintNumeCon(void); //Afiseaza numele la consola ...
        
public:
        int          IntPublic;
        double       DoublePublic;

        //Declararea functiilor membru publice ale clasei Clasa1 : metodele clasei
        Clasa1(void); //Constructor implicit ...
        Clasa1(Clasa1 &); //Constructor de copiere ...
        Clasa1(int, double, const char *, int, double, int, double); //Constructor ...
        Clasa1(const char *); //Constructor ... .
        //Modificatorul const asigura faptul ca valoarea de la adresa transferata nu va fi      //modificata.
        //Testul se face la compilare.
        
        ~Clasa1(); //Destructor ...
        
        //Atribuie membrilor valorile precizate ca parametri ...
        void Set(int, double, const char *, int, double, int, double);
        void SetNume(const char *);
        void SetPrivate(int, double);
        void SetProtected(int, double);
        void SetPublic(int, double);

       //Functii membru "inline"
       //Returneaza referinta -> un pseudonim pentru obiectul returnat -> este lvalue si rvalue
       int & GetPrivateInt(void) {return IntPrivate;}
       double & GetPrivateDouble(void) {return DoublePrivate;}
       int & GetProtectedInt(void) {return IntProtected;}
       double & GetProtectedDouble(void) {return DoubleProtected;}

       void PrintCon(void); //Afiseaza valorile variabilelor membru la consola ...
       void ScanCon(void); //Citeste valorile variabilelor membru de la consola ...

};



//Definitia functiilor membru ale clasei Clasa1.
//Se foloseste operatorul de rezolutie pentru a specifica
//clasa careia ii apartine functia.
Clasa1::Clasa1(void)
{
    Nume = nullptr;
    IntPrivate = IntProtected = IntPublic = 0;
    DoublePrivate = DoubleProtected = DoublePublic = 0.0;
    Mesaj("S-a apelat constructorul implicit al clasei \"Clasa1\"" );
}


Clasa1::Clasa1(Clasa1 &RefObiectClasa1)
{
    Nume = RefObiectClasa1.Nume;
    IntPrivate = RefObiectClasa1.IntPrivate;
    DoublePrivate = RefObiectClasa1.DoublePrivate;
    IntProtected = RefObiectClasa1.IntProtected;
    DoubleProtected = RefObiectClasa1.DoubleProtected;
    IntPublic = RefObiectClasa1.IntPublic;
    DoublePublic = RefObiectClasa1.DoublePublic;

    Mesaj("S-a apelat constructorul de copiere al clasei \"Clasa1\"");
}

Clasa1::Clasa1(int IntPrivate, double DoublePrivate, const char *NumeObiect,
                        int IntProtected, double DoublePotected,
                        int IntPublic, double DoublePublic)
{
#ifdef _APEL_METODA_
    Nume = nullptr; //De ce se face aceasta atribuire in acest moment ?
    Set(IntPrivate, DoublePrivate, NumeObiect, IntProtected, DoublePotected, IntPublic, DoublePublic);
#else
    Clasa1::IntPrivate = IntPrivate; //Se utilizeaza operatorul de rezolutie in cadrul clasei...
    Clasa1::DoublePrivate = DoublePrivate;
    Nume = NumeObiect;
    Clasa1::IntProtected = IntProtected;
    Clasa1::DoubleProtected = DoublePotected;
    Clasa1::IntPublic = IntPublic;
    Clasa1::DoublePublic = DoublePublic;
#endif
    Mesaj("S-a apelat constructorul cu parametri al clasei \"Clasa1\"");
}

Clasa1::Clasa1(const char *NumeObiect)
{
    Nume = NumeObiect;
    IntPrivate = IntProtected = IntPublic = 0;
    DoublePrivate = DoubleProtected = DoublePublic = 0.0;
    Mesaj("S-a apelat constructorul cu parametri al clasei \"Clasa1\"");
}

Clasa1::~Clasa1()
{
    Mesaj("S-a apelat destructorul clasei \"Clasa1\"");
}

void Clasa1::Mesaj(char *Mesaj)
{
    PrintNumeCon();
    cout << " : " << Mesaj << endl;
    cout << "Apasati o tasta pentru a continua..."<<endl;
    _getch();
}

void Clasa1::Set(int IntPrivateParam, double DoublePrivateParam, const char * NumeParam,
                        int IntProtectedParam, double DoubleProtectedParam,
                        int IntPublicParam, double DoublePublicParam)
{
#ifdef _APEL_METODA_
    SetNume(NumeParam);
    SetPrivate(IntPrivateParam, DoublePrivateParam);
    SetProtected(IntProtectedParam, DoubleProtectedParam);
    SetPublic(IntPublicParam, DoublePublicParam);
#else
    IntPrivate = IntPrivateParam;
    DoublePrivate = DoublePrivateParam;
    if(Nume==nullptr) //Daca obiectul nu are nume ...
        Nume = NumeParam;
    IntProtected = IntProtectedParam;
    DoubleProtected = DoubleProtectedParam;
    IntPublic = IntPublicParam;
    DoublePublic = DoublePublicParam;
#endif
}

void Clasa1::SetNume(const char *NumeParam)
{
    if(!Nume)
        Nume = NumeParam;
}

void Clasa1::SetPrivate(int Int, double Double)
{
    IntPrivate = Int;
    DoublePrivate = Double;
}

void Clasa1::SetProtected(int Int, double Double)
{
    IntProtected = Int;
    DoubleProtected = Double;
}

void Clasa1::SetPublic(int Int, double Double)
{
    IntPublic = Int;
    DoublePublic = Double;
}

void Clasa1::PrintNumeCon(void)
{
    cout << "obiectul ";
    if(Nume != nullptr) //Daca Nume este diferit de nullptr
        cout << Nume;
    else //Daca Nume == nullptr
        cout << "Anonim ";
}

void Clasa1::PrintCon(void)
{
    cout << endl;
    PrintNumeCon();

    cout << " : \n" << "Valoarea \"int\" private:\t\t\t" << IntPrivate << endl; 
    //Acces indirect la membru private ... 

    cout << "Valoarea \"double\" private:\t\t" << DoublePrivate << endl; 
    //Acces indirect la membru private ... 

    cout << "Valoarea \"int\" protected:\t\t" << IntProtected << endl; 
    //Acces indirect la membru protected ... 

    cout << "Valoarea \"double\" protected:\t\t" << DoubleProtected << endl; 
    //Acces indirect la membru protected ... 

    cout << "Valoarea \"int\" public:\t\t\t" << IntPublic << endl; 
    //Acces direct la membru public ... 

    cout << "Valoarea \"double\" public:\t\t" << DoublePublic << endl; 
    //Acces direct la membru public ...

    cout << endl;
}

void Clasa1::ScanCon(void)
{
    cout << endl << "Pentru ";
    PrintNumeCon();
    cout << endl << "Introduceti:" << endl;
    cout << "Valoarea \"int\" private:" << endl;
    cin >> IntPrivate; //Acces indirect la membru private ... 
    cout << "Valoarea \"double\" private:" << endl;
    cin >> DoublePrivate; //Acces indirect la membru private ... 
    cout << "Valoarea \"int\" protected:" << endl;
    cin >> IntProtected; //Acces indirect la membru protected ... 
    cout << "Valoarea \"double\" protected:" << endl;
    cin >> DoubleProtected; //Acces indirect la membru protected ... 
    cout << "Valoarea \"int\" public:" << endl;
    cin >> IntPublic; //Acces direct la membru public ... 
    cout << "Valoarea \"double\" public:" << endl;
    cin >> DoublePublic; //Acces direct la membru public ...
    cout << endl;
}

//Obiect global de tipul Clasa1:
Clasa1 Obiect1; //Se apeleaza constructorul implicit


int main(void)
{
    //Citirea de la consola a valorilor pentru membrii unui obiect ... .
    cout << "Introduceti pentru Obiect1:\nValoarea \"int\" private" << endl;
    cin >> Obiect1.GetPrivateInt(); //Acces indirect la membru private ... 

    cout << "Valoarea \"double\" private" << endl;
    cin >> Obiect1.GetPrivateDouble(); //Acces indirect la membru private ... 

    cout << "Valoarea \"int\" protected" << endl;
    cin >> Obiect1.GetProtectedInt(); //Acces indirect la membru protected ... 

    cout << "Valoarea \"double\" protected" << endl;
    cin >> Obiect1.GetProtectedDouble(); //Acces indirect la membru protected ... 

    cout << "Valoarea \"int\" public" << endl;
    cin >> Obiect1.IntPublic; //Acces direct la membru public ... 

    cout << "Valoarea \"double\" public" << endl;
    cin >> Obiect1.DoublePublic; //Acces direct la membru public ...

    //Scrierea la consola a valorilor membrilor unui obiect ... .
    Obiect1.PrintCon();
    
    Clasa1 Obiect2(Obiect1); //Se apeleaza constructorul de copiere ...

    cout << endl << "Valorile unei copii:" << endl;
    Obiect2.PrintCon();

    int                 Int1, Int2, Int3;
    double           Double1, Double2, Double3;

    cout << "Introduceti trei valori \"int\"" << endl;
    cin >> Int1 >> Int2 >> Int3;
    cout << "Introduceti trei valori \"double\"" << endl;
    cin >> Double1 >> Double2 >> Double3;
    
    Clasa1 Obiect3(Int1, Double1, "Obiect 3", Int2, Double2, Int3, Double3);
    Obiect3.PrintCon();

    //Instructiunea compusa : bloc
    {
        Clasa1 Obiect4("\"Obiect local unui bloc\"");
        Obiect4.ScanCon();
        Obiect4.PrintCon();
    }

    //Alocare dinamica de memorie pentru un obiect din clasa Clasa1
    Clasa1 *PtrClasa1;
    PtrClasa1 = new Clasa1("\"Obiect alocat dinamic\"");
    if(PtrClasa1)
    {
        PtrClasa1->ScanCon();
        PtrClasa1->PrintCon();
    }
    //Eliberarea memoriei
    if(PtrClasa1)
    {
        delete PtrClasa1;
        PtrClasa1 = nullptr; //Obicei bun ...
    }

    int Dim;
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> Dim;
    //Alocare dinamica de memorie pentru un vector de obiecte din clasa Clasa1
    PtrClasa1 = new Clasa1[Dim]; //Se apeleaza constructorul implicit de Dim ori ...



    if(PtrClasa1)
    {
        Clasa1 *PtrClasa1Temp = PtrClasa1;
        for(int Contor = 0; Contor < Dim; Contor++)
        {
            cout << endl << "Obiectul " << Contor << " alocat dinamic:" << endl;
            (PtrClasa1Temp++)->PrintCon();
            cout << "Apasati o tasta pentru a continua ...";
            _getch();
        }
        cout << endl;
    }
    //Eliberarea memoriei
    if(PtrClasa1)
    {
        delete []PtrClasa1;
        //delete PtrClasa1; //nu este apelat destructorul decat pentru primul obiect ...
        PtrClasa1 = nullptr; //Obicei bun ...
    }

    //Alocare memoriei folosind malloc() ... .
    //Nu se apeleaza nici constructor nici destructor !!! .
    //PtrClasa1 = (Clasa1 *)malloc(Dim * sizeof(class Clasa1));
    //if(!PtrClasa1)
    //{
    //    cout << "Eroare la alocarea dinamica de memorie ..." << endl;
    //    return 1;
   // }
   // for(int Contor = 0; Contor < Dim; Contor++)
   //     PtrClasa1[Contor].ScanCon();
   // for(int Contor = 0; Contor < Dim; Contor++)
   //     PtrClasa1[Contor].PrintCon();
        
    //if(PtrClasa1)
   // {
   //     free(PtrClasa1);
   // }

    //Alocare memoriei folosind calloc() ... .
    //Nu se apeleaza nici constructor nici destructor !!! .
   // PtrClasa1 = (Clasa1 *)calloc(Dim, sizeof(class Clasa1));
   // if(PtrClasa1)
   // {
  //      free(PtrClasa1);
   // }
    
    return 0;
}

