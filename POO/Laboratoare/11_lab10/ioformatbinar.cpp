#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string.h>

using namespace std;
enum Error
{
    Success,
    Error
};

//Constanta pi cu valoarea sugerata de nume.
const double pi=3.14159265358979323846;

int main(void)
{
    //Siruri de caractere utilizat in mesajele de eroare
    //la manipularea streamurilor conectate la fisiere.
    char        *OpenError="Eroare la deschiderea fisierului ";
    char        *WriteError="Eroare la scrierea in fisierul ";
    char        *ReadError="Eroare la citirea din fisierul ";
    char        *KbdError="Eroare la citirea de la tastatura !!!";
    //Stream in care se va scrie formatat ...
    fstream    FileFormat;
    //Stream in care se va scrie binar ...
    fstream    FileBinar;
    //Sir de caractrere in care se citeste numele
    //fisierului in care se va scrie formatat ...
    char        FileNameFormat[256];
    //Sir de caractrere in care se citeste numele
    //fisierului in care se va scrie binar ...
    char        FileNameBinar[256];
    //Numarul de valori scrise / citite.
    int         N;
    //"Precizia" cu care se face iesirea cu format.
    int         Prec;

    cout << "Numele fisierului cu format : ";
    cin >> FileNameFormat;
	cout<<FileNameFormat<<endl;
    //Nu este deloc rau sa verificam succesul operatiei.
    if(cin.fail())
    {
        cerr << KbdError << endl;
        return Error;
    }
    cout << "Numarul de cifre semnificative pentru mantisa : ";
    cin >> Prec;
    if(cin.fail())
    {
        cerr << KbdError << endl;
        return Error;
    }
    cout << "Numele fisierului binar : ";
    cin >> FileNameBinar;
	cout<<FileNameBinar<<endl;
    if(cin.fail())
    {
        cerr << KbdError << endl;
        return Error;
    }
    //Ne asiguram ca numele fisierelor nu coincid ...
    if(!strcmp(FileNameFormat, FileNameBinar))
    {
        cerr << "Numele fisierelor coincid ! " << FileNameFormat << " == " << FileNameBinar << endl;
        return Error;
    }

    //Deschiderea fisierului cu format.
    //Implicit streamurile sunt formatate.
    //S-a setat formatul cu mantisa si exponent (scientific)
    //Pentru valorile in virgula mobila.
	FileFormat.open(FileNameFormat, ios::out );
	
	if(!FileFormat)
    {
        cerr << OpenError << FileNameFormat << endl;
        return Error;
    }
 

    //Se seteaza "precizia" pentru iesirea cu format
    //la valoarea 10. Pentru formatul "scientific" reprezinta
    //numarul de cifre semnificative reprezentate pentru mantisa.
    //S-a utilizat functia membru precision(int)
    FileFormat.precision(Prec);

    //Deschiderea fisierului binar.
    FileBinar.open(FileNameBinar, ios::out | ios::binary);
    if(!FileBinar)
    {
        cerr << OpenError << FileNameFormat << endl;
        //Urmatoarea instructiune poate lipsi,
        //in acest context fiind oricum apelat
        //destructorul obiectului FileFormat
        FileFormat.close();
        return Error;
    }

    cout << "Numarul de valori scrise / citite : ";
    cin >> N;
    if(cin.fail())
    {
        cerr << KbdError << endl;
        return Error;
    }

    double Val;
	int i;
    for( i = 0; i < N; i++)
    {
        Val = tan(pi / (i + 1));
        //Testarea erorii se face cu utilizarea referintei
        //returnate de operatorul de insertie.
        if((FileFormat << Val << ' ').fail())
        {
            cerr << WriteError << FileNameFormat << endl;
            return Error;
        }
        //Conversia pointerului la Val(double)
        //in pointer la sir de caractere cu lungimea
        //egala cu numarul de octeti ocupati de un
        //obiect de tip double. Metoda write copie la
        //iesire, octet cu octet formatul intern de
        //reprezentare al lui Val
        FileBinar.write((char *)&Val, sizeof(Val));
        //O alta varianta de testare a erorii
        //fara utilizarea referintei returnate de write.
        if(FileBinar.fail())
        {
            cerr << WriteError << FileNameBinar << endl;
            return Error;
        }
    }
    //Aici este necesara inchiderea fisierelor.
    FileFormat.close();
    FileBinar.close();

    //Se folosesc aceleasi obiecte pentru a testa citirea
    //cu format si binara. Operatiile care se fac reprezinta
    //exact operatiile inverse de la scriere.
    FileFormat.open(FileNameFormat, ios::in);
    //Alta varianta de testare a starii obiectului
    if(!FileFormat)
    {
        cerr << OpenError << FileNameFormat << endl;
        return Error;
    }

    FileBinar.open(FileNameBinar, ios::binary | ios::in);
    if(FileBinar.fail())
    {
        cerr << OpenError << FileNameBinar << endl;
        return Error;
    }

    double      ValBinar, ValFormat;
    //Se utilizeaza i pentru a contoriza numarul
    //de operatii de citire realizate.
    i = -1; //De ce s-a atribuit valoarea -1 lui i ?
    //Se evalueaza si eroare maxima absoluta.
    double      MaxError(0);
    double      MaxErrorTemp;
    double      MaxErrorFormat;
    double      MaxErrorBinar;
    //Alta varianta de testare a validitatii
    //operatiilor SI pentru un stream SI pentru
    //celalalt
    while(FileBinar.good() && FileFormat.good())
	{
       
		FileFormat >> ValFormat;
        FileBinar.read((char *)&ValBinar, sizeof(ValBinar));
        i++;
        MaxErrorTemp = fabs(ValFormat - ValBinar);
        if(MaxError < MaxErrorTemp)
        {
            MaxError = MaxErrorTemp;
            MaxErrorFormat = ValFormat;
            MaxErrorBinar = ValBinar;
        } 
    }
    if(i != N)
    {
        cerr << "S-au citit corect " << i << " valori din " << N << '!' << endl;
        return Error;
    }
    cout << "Eroarea maxima obtinuta la citire este : " << MaxError << ',' << endl;
    cout << "si s-a obtinut pentru valorile : " << endl << "Format\t\t\tBinar" << endl;
    //O alta forma de setare a numarului de cifre semnificative ...
    //S-a utilizat manipulatorul setprecision(int)
    cout << setprecision(Prec+1) << MaxErrorFormat << '\t' << MaxErrorBinar << endl;
    //Este elegant ca si aici fisierele sa fie inchise, desi va urma imediat
    //apelul la destructorul clasei fstream pentru cele doua obiecte.
    FileFormat.close();
    FileBinar.close();

	cin.ignore(10,'\n');
    cin.get();
    return Success;
}