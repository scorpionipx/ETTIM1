#include <iostream.h>
#include "binary_search.hpp"

//Valori returnate de functia main.
enum Err
{
    Success,
    Error
};

//Clasa care este utilizata pentru tratarea exceptiilor
//care apar la alocarea dinamica de memorie si care pot fi
//rezolvate pe loc in urma unui compromis.
class AllocError {};
//Clasa care este utilizata pentru tratarea exceptiilor fatale la alocarea memoriei.
class AllocFatalError {};
//Clasa care este utilizata pentru tratarea erorilor de citire de la tastatura.
class ReadError
{
public:
        int *PtrInt;
        ReadError(void) : PtrInt(NULL) {}
        ReadError(int *P) : PtrInt(P) {}
};

//Alocarea memoriei se face numai cu aceasta functie (Alloc).
int * Alloc(int N)
{
    int *PtrInt;
    if(!N)
        throw AllocError(); //Eroare fatala ...
    PtrInt = new int[N];
    if(!PtrInt)
        throw AllocError();
    return PtrInt;
}

//Eliberarea memoriei se face numai cu aceasta functie (Free).
//Parametrul functiei are tipul: referinta la pointer la intreg.
void Free(int * &PtrInt)
{
    //Memoria a fost deja eliberata.
    if(!PtrInt)
        return;
    //Daca memoria nu a fost eliberata o eliberam acum.
    delete []PtrInt;
    //Nu uitam sa "marcam" pointerul respectiv
    //cu valoarea NULL in caz ca functia este
    //apelata din nou cu acelasi pointer.
    //Acesta este motivul pentru care am transferat
    //referinta la pointer si nu direct valoarea pointerului.
    PtrInt = NULL;
}


//Functie care incearca sa construiasca problema.
void DoEverithing(void)
{
    
    int NrElem;
    cout << "Numarul de elemente din vector : ";
    cin >> NrElem;
    if(!cin)
        //Inca nu avem nici un vector.
        throw ReadError();
    //Daca s-a citit corect NrElem ne asiguram ca valoarea citita este pozitiva.
    if(NrElem < 1)
        throw ReadError();

    //Aici apare si vectorul.
    int *VectorInt;

    //Se ilustreaza o strategie (nu cea mai buna)
    //de rezolvare a unei erori
    //fara sa se paraseasca programul ...
TryAgain: //Nu va speriati de eticheta de salt neconditionat !!!
    try //Incearca
    {
        VectorInt = Alloc(NrElem);
    }
    catch(AllocError) //In caz de eroare ...
    {
        if(NrElem < 1) //si daca N este suficient de mare ...
        {
            //Eroarea este FATALA: nu se poate
            //aloca memorie dinamica nici macar
            //pentru UN intrag!!!
            throw AllocFatalError();
        }
        cerr << "Nu sa putut aloca memorie pentru un vector de dimensiune " << NrElem;
        NrElem--; //Decrementeaza NrElem
        cerr << ". Se incearca alocarea pentru un vector de dimensiune " << NrElem << '!' << endl;
        //Nu va speriati nici de instructiune de salt neconditionat.
        goto TryAgain; //Mai incearca o data ...
    }
    //In acest moment vectorul este pregatit.
    //In alte circumstante valorile memorate in vector
    //ar rezulta dintr-un proces mai interesant.
    //Pentru utilizare functiei binary_search vectorul
    //trebuie sa fie si sortat in ordine crescatoare.
    //Pentru a nu complica prea mult lucrurile vom
    //incarca vectorul artificial:
    int *PtrVector(VectorInt);
    for(int i = 0; i < NrElem; i++)
        *PtrVector++ = i;

    //De aceasta data functia binary search are ca parametri
    //doi pointeri care marcheaza inceputul si urmatorul
    //element de dupa sfarsitul zonei din vector unde se face cautarea.
    int *begin, *end;
    int Depl;
    cout << "In domeniul : [0, " << NrElem -1 << ")" << endl;
    cout << "Primul element al domeniului de cautare : ";
    cin >> Depl;
    if(!cin)
        throw ReadError(VectorInt);
    //Sa ne asiguram ca stim ce facem. Altfel treburile scapa de sub control.
    if(Depl < 0 || Depl >= NrElem - 1)
        throw ReadError(VectorInt);
    begin = VectorInt + Depl;

    cout << "Ultimul element al domeniului de cautare : ";
    cin >> Depl;
    if(!cin)
        throw ReadError(VectorInt);
    //Sa ne asiguram ca stim ce facem. Altfel treburile scapa de sub control.
    if(Depl < 0 || Depl >= NrElem - 1)
        throw ReadError(VectorInt);
    end = VectorInt + Depl;
    //Sa vedem daca nu cumva intervalul specificat este convex.
    //Altfel lucrurile scapa de asemenea de sub control.
    if(begin >= end)
        throw ReadError(VectorInt);

    int Val; //Valoarea elementului care este cautat.
    cout << "Valoarea elementului care trebuie cautat : " << endl;
    cin >> Val;
    if(!cin)
        throw ReadError(VectorInt);

    //In acest moment se poate incerca utilizarea functiei binary_search.
    const int *Result; //const -> vezi prototipul functiei binary_search ...
    Result = binary_search(begin, end, Val);
    if(Result == end)
        cout << "Valoarea " << Val << " nu se afla in vector." << endl;
    else
        //conversia la int * este posibila deoarece operatorul << are ca parametru int const *.
        cout << "Valoarea " << Val << " este in domeniul de cautare la adresa " << (int *)Result << endl; 
    Free(VectorInt);
}


int main(void)
{
    try
    {
        DoEverithing();
    }
    catch(AllocFatalError)
    {
        cerr << "Masina are ceva foarte grav ..." << endl;
        //Nu este nici un vector de eliberat.
        return Error;
    }
    //Informatia despre eroare este codificata in Error ...
    catch(ReadError Caught)
    {
        //Nu mai insistam, desi am fi putut ...
        cerr << "Eroare la citirea unei valori de la tastatura !" << endl;
        //Nu uitam sa eliberam memoria care a fost eventual alocata.
        //Informatia despre eroare este chiar valoarea pointerului.
        Free(Caught.PtrInt);
        return Error;
    }
    return Success;
}
