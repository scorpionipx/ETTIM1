/************************************************
PrintM.cpp
Definitia functiei PrintMessage ...
************************************************/
#include "hello.hpp"
using namespace std;
//Variabile locale fisierului sursa.
char Mesaj1[] = "Mesajul este: %s\n";
char Mesaj2[] = "Mesajul este: ";

void PrintMessage(char *Mesaj)
{
#ifdef IO_C
    printf("Mesajul este: %s\n", Mesaj);
    printf(Mesaj1, Mesaj);
#endif
#ifdef IO_CPP
    cout << Mesaj2 << Mesaj << endl;
#endif
}
