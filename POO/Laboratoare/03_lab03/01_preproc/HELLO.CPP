
/************************************************
Hello.cpp
Definitia functiei main ...
************************************************/
#include "hello.hpp"
using namespace std;

//Linie de comentariu C++ ...
/*Comentariu C ...*/

void main(void)
{
    char Mesaj1[] = "\nHello C++ world !\n";    
    //Sir de caractere initializat cu constanta   
    //sir de caractere ...
    char Mesaj2[60]; //Sir de 60 de caractere: 
    //Mesaj2[0] este primul caracter ...
    char *Mesaj3 = "\nAti introdus mesajul: ";  
    //Mesaj3 este pointer la sir constant de 
    //caractere ...
    char *Mesaj4 = "\nAti introdus mesajul: %s\n";
    //Mesaj4 este pointer la sir constant de 
    //caractere ...



    do
    {
        PrintMessage(Mesaj1);
if(Question("\nVreti sa introduceti un mesaj?"))
        {
#ifdef IO_CPP
            //C++
cout << endl << "Introduceti mesajul pentru C++ !";     
  cout << endl;
  cin >> Mesaj2;
            cout << Mesaj3 << Mesaj2 << endl;
#endif
#ifdef IO_C
            //C
       puts("\nIntroduceti mesajul pentru C !");
            scanf("%s", Mesaj2);
            printf(Mesaj4, Mesaj2);
            //Apel de functie ...
#endif
            PrintMessage(Mesaj2);
        }
    }
    while(Question("\nRepetam ?"));
}
 

