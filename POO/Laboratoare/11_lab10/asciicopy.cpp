#include <iostream>
#include <fstream>
using namespace std;
enum Err
{
    Success,
    Error
};

//Programul are parametri in linia de comanda
int main(int argc, char *argv[])
{
    //Sunt sau nu furnizate corect argumentele ?!?
    switch(argc)
    {
        case 3:
                cerr << argv[0] << " realizeaza copia ASCII : " << argv[1] << " -> " << argv[2] << ' ';
                break;
        default :
                cerr << "Utilizare : " << argv[0] << " sursa destinatie" << endl;
                return Error;
    }

    char        *OpenError="Eroare la deschiderea fisierului ";
    char        *WriteError="Eroare la scrierea in fisierul ";
    char        *ReadError="Eroare la citirea din fisierul ";

    ifstream    In(argv[1]);
    if(!In)
    {
        cerr << OpenError << argv[1] << endl;
        return Error;
    }
    ofstream    Out(argv[2]);
    if(!Out)
    {
        cerr << OpenError << argv[2] << endl;
        return Error;
    }

    char        CTemp;
    //Cat timp nu s-a ajuns la sfarsitul fisierului de intrare ...
    while(!In.eof())
    {
        CTemp = In.get();
        //...si nu a aparut o eroare la intrare ...
        if(In.good())
            Out.put(CTemp);
        else if(!In.eof())
        {
            cerr << ReadError << argv[1] << endl;
            return Error;
        }
        //...si nu a aparut o eroare la iesire ...
        if(Out.fail())
        {
            cerr << WriteError << argv[2] << endl;
            return Error;
        }
    }
    //Foarte sanatos ...
    In.close();
    Out.close();
    
    cerr << "O.K." << endl;
    return Success;
}
